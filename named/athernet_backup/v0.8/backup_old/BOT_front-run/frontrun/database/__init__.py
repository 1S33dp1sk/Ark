import sqlite3

# helpers

def create_connection(db_file='/home/kj/BOT_front-run/frontrun/database/main.db'):
    """ 
    create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file, check_same_thread=False)
    except:
        print("There's an error with database connection")
    return conn

def sqlify(ch_param):
    temp_ch = ''
    temp_params = ()
    for i in ch_param.keys():
        temp_ch += ' %s = ? ,'%i
        temp_params += (ch_param[i],)
    temp_ch = temp_ch[:-1]
    return temp_ch, temp_params



# General 
'''
1.id 
2.bot_name
3.total_investment
4.amount_to_trade
5.profit_address
6.profitable_trades
7.transfer_profits_count
8.total_profits
9.tokens_count
10.slippage
11.sender_addr
12.private_key
'''
def get_general_info(conn):
    """
    query all rows in the general table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        cur = conn.cursor()
        cur.execute('''SELECT * FROM General;''')
        row = cur.fetchall()
        return row
    except:
        print('something went wrong')
        
   

def update_general_info(conn, info):
    """
    update any param on token
    :param conn:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        temp_ch,temp_params = sqlify(info)
        sql_stmnt = ''' UPDATE General SET 
                            %s
                    WHERE id = ?;'''%temp_ch
        cur = conn.cursor()
        temp_params += (1,)
        cur.execute(sql_stmnt, temp_params)
        conn.commit()
        return       
    except:
        print('something went wrong')
    



# Tokens 
'''
1.id
2.token_name
3.did_add
4.price
5.contract_address
6.trigger
7.decimals
'''
def get_all_tokens(conn):
    """
    query all rows in the tokens table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        cur = conn.cursor()
        cur.execute('''SELECT * FROM Tokens;''')
        rows = cur.fetchall()
        return rows
    except Exception as ex:
        print('something went wrong')
        print('in get tokens:\n')
        print(ex)
def add_new_token(conn, token):
    """
    Create a new token
    :param conn:
    :param token parameters:
    :return:
    """

    try:
        sql_stmnt = ''' INSERT INTO Tokens(id,token_name,did_add,price,contract_address,trigger,decimals) VALUES(NULL,?,?,?,?,?,?) '''
        cur = conn.cursor()
        cur.execute(sql_stmnt, token)
        conn.commit()
        tkn_cnt = int(get_general_info(conn)[0][-4])+1
        update_general_info(conn,{'tokens_count':tkn_cnt})
        return cur.lastrowid
    except:
        print('something went wrong')
        
def remove_token(conn, id):
    """
    Delete a task by task id
    :param conn:  Connection to the SQLite database
    :param id: id of the task
    :return:
    """
    try:
        sql_stmnt = 'DELETE FROM Tokens WHERE id=?'
        cur = conn.cursor()
        cur.execute(sql_stmnt, (id,))
        conn.commit()
        return
    except:
        print('something went wrong')
        
def get_token(conn, id):
    """
    query specifc row in the tokens table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        sql_stmnt = '''SELECT * FROM Tokens WHERE id=?'''
        cur = conn.cursor()
        cur.execute(sql_stmnt,(id,))
        row = cur.execute.fetchall()
        return row
    except:
        print('something went wrong')
        
def update_token(conn, id, ch_param):
    """
    update any param on token
    :param conn:
    :param id:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        temp_ch, temp_params = sqlify(ch_param)
        sql_stmnt = ''' UPDATE Tokens SET 
                    %s
                    WHERE id = ?;'''%temp_ch
        cur = conn.cursor()
        temp_params += (id,)
        cur.execute(sql_stmnt, temp_params)
        conn.commit()
        return
    except:
        print('something went wrong')
        



# Transactions 
'''
1.id  
2.txn_in_hash 
3.txn_in_price 
4.qty_native 
5.qty_bnb
6.triger_ref
7.token_name
8.txn_out_hash
9.txn_out_price
10.profit
11.done
'''

def get_all_transactions(conn, limit=50):
    """
    query all rows in the transactions table
    :param conn: the Connection object
    :return: rows from the table
    """
    if limit:
        sql_stmnt = '''SELECT * FROM Transactions LIMIT %d;'''%limit
    else:
        sql_stmnt = '''SELECT * FROM Transactions'''

    try:
        cur = conn.cursor()
        cur.execute(sql_stmnt)
        rows = cur.fetchall()
        return rows
    except:
        print('something went wrong')
        

def add_new_transaction(conn, transaction, trigger_ref):
    """
    Create a new transaction
    :param conn:
    :param token parameters:
    :return:
    """
    try:
        sql_stmnt = ''' INSERT INTO Transactions(id,txn_in_hash,txn_in_price,qty_native,qty_bnb,triger_ref,token_name,txn_out_hash,txn_out_price,profit,done) VALUES(NULL,?,?,?,?,?,?,NULL,NULL,NULL,NULL) '''
        cur = conn.cursor()
        cur.execute(sql_stmnt, (transaction, trigger_ref))
        conn.commit()
        return cur.lastrowid
    except:
        print('something went wrong')
        

def get_transaction(conn, prop):
    """
    query specifc row in the tokens table
    :param conn: the Connection object
    :param prop: any property value of the transaction from a dict {propname : propvalue}
    :return: rows from the table
    """
    try:
        if prop == None:
            return get_all_transactions(conn)
        qu_prop,qu_value = sqlify(prop)
        sql_stmnt = ''' SELECT * FROM Transactions WHERE %s;'''%qu_prop
        cur = conn.cursor()
        cur.execute(sql_stmnt, qu_value)
        rows = cur.fetchall()
        return rows
    except:
        print('something went wrong')
        

def update_transactions(conn,id, ch_param):
    try:
        temp_ch, temp_params = sqlify(ch_param)
        sql_stmnt = ''' UPDATE Transactions SET 
                    %s
                    WHERE id = ?;'''%temp_ch
        cur = conn.cursor()
        temp_params += (id,)
        cur.execute(sql_stmnt, temp_params)
        conn.commit()
        return
    except:
        print('something went wrong')
        


# Triggers
'''
1.id
2.ref
3.token_name
4.txn_hash
5.qty_native
6.qty_bnb
'''
def add_new_trigger(conn, ch_param):
    """
    Create a new transaction
    :param conn:
    :param token parameters:
    :return:
    """
    try:
        temp_ch, temp_params = sqlify(ch_param)
        cur = conn.cursor()
        cur.execute("SELECT * FROM table ORDER BY id DESC LIMIT 1")
        last_ref = cur.fetchone()[0]
        new_ref = 'ref_%d'%(last_ref+1)
        sql_stmnt = ''' INSERT INTO Triggers(id,ref,token_name,txn_hash,qty_native,qty_bnb) VALUES(NULL,?,?,?,?,?) '''
        final_params = (new_ref,)
        final_params += temp_params
        cur.execute(sql_stmnt, final_params)
        conn.commit()
        return cur.lastrowid    
    except:
        print('something went wrong')
        

def update_trigger(conn, ref, ch_param):
    """
    update any param on trigger
    :param conn:
    :param id:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        temp_ch, temp_params = sqlify(ch_param)
        sql_stmnt = ''' UPDATE Triggers SET 
                    %s
                    WHERE ref = ?;'''%temp_ch
        cur = conn.cursor()
        temp_params += (ref,)
        cur.execute(sql_stmnt, temp_params)
        conn.commit()
        return
    except:
        print('something went wrong')
        

def retireve_all_triggers(conn):
    '''
    Fetch all the different triggers that did not add the information for except for transaction hash
    mainly update the different props for said trigger such as token_name, transaction_price, quantity,etc...
    :param conn:
    :return: rows
    '''
    try:
        sql_stmnt = ''' SELECT * FROM Triggers;'''
        cur = conn.cursor()
        cur.execute(sql_stmnt)
        rows = cur.fetchall()
        return rows
    except:
        print('something went wrong')
        


