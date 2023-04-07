import sqlite3

# helpers

db_filename = 'main.db'

def create_connection(db_file):
    """ 
    create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file)
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


# Fetching

def fetch_trigger_info(txn_hash):
    # return the function via a dict with keys and values in a single dict 
    return


# General (id, bot_name, total_investment, amount_to_trade, profit_address, profitable_trades, transfer_profits_count, total_profits, tokens_count)

def get_general_info(conn):
    """
    query all rows in the general table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    cur = conn.cursor()
    cur.execute('''SELECT * FROM General;''')
    row = cur.fetchall()
    return row

def update_general_info(conn, info):
    """
    update any param on token
    :param conn:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
    temp_ch,temp_params = sqlify(info)
    sql_stmnt = ''' UPDATE General SET 
                %s
                WHERE id = ?;'''%temp_ch
    cur = conn.cursor()
    cur.execute(sql_stmnt, temp_params+(1,))
    conn.commit()
    return



# Tokens (id, token_name, did_add, price, slippage, contract_address)

def get_all_tokens(conn):
    """
    query all rows in the tokens table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
    cur = conn.cursor()
    cur.execute('''SELECT * FROM Tokens;''')
    rows = cur.fetchall()
    return rows

def add_new_token(conn, token):
    """
    Create a new token
    :param conn:
    :param token parameters:
    :return:
    """

    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = ''' INSERT INTO Tokens(id,token_name,contract_address,did_add,price) VALUES(NULL,?,?,?,?) '''
    cur = conn.cursor()
    cur.execute(sql_stmnt, token)
    conn.commit()
    tkn_cnt = int(get_general_info(conn)[0][-1])+1
    update_general_info(conn,{'tokens_count':tkn_cnt})
    return cur.lastrowid

def remove_token(conn, id):
    """
    Delete a task by task id
    :param conn:  Connection to the SQLite database
    :param id: id of the task
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = 'DELETE FROM Tokens WHERE id=?'
    cur = conn.cursor()
    cur.execute(sql_stmnt, (id,))
    conn.commit()
    return

def get_token(conn, id):
    """
    query specifc row in the tokens table
    :param conn: the Connection object
    :return: rows from the table
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = '''SELECT * FROM Tokens WHERE id=?'''
    cur = conn.cursor()
    cur.execute(sql_stmnt,(id,))
    row = cur.execute.fetchall()
    return row

def update_token(conn, id, ch_param):
    """
    update any param on token
    :param conn:
    :param id:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    temp_ch, temp_params = sqlify(ch_param)
    sql_stmnt = ''' UPDATE Tokens SET 
                %s
                WHERE id = ?;'''%temp_ch
    cur = conn.cursor()
    cur.execute(sql_stmnt, (temp_params,id))
    conn.commit()
    return


# Transactions (id, token_name, txn_hash, txn_price, qty_native, qty_bnb, triger_ref)


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
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    cur = conn.cursor()
    cur.execute(sql_stmnt)
    rows = cur.fetchall()
    return rows

def add_new_transaction(conn, transaction, trigger_ref):
    """
    Create a new transaction
    :param conn:
    :param token parameters:
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = ''' INSERT INTO Transactions(id,txn_in_hash,txn_in_price,qty_native,qty_bnb,triger_ref,token_name,txn_out_hash,txn_out_price,profit,done) VALUES(NULL,?,?,?,?,?,?,NULL,NULL,NULL,NULL) '''
    cur = conn.cursor()
    cur.execute(sql_stmnt, (transaction, trigger_ref))
    conn.commit()
    return cur.lastrowid

def get_transaction(conn, prop):
    """
    query specifc row in the tokens table
    :param conn: the Connection object
    :param prop: any property value of the transaction from a dict {propname : propvalue}
    :return: rows from the table
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    if prop == None:
        return get_all_transactions(conn, None)

    qu_prop,qu_value = sqlify(prop)
    sql_stmnt = ''' SELECT * FROM Tokens WHERE %s;'''%qu_prop
    cur = conn.cursor()
    cur.execute(sql_stmnt, qu_value)
    rows = cur.fetchall()
    return rows

def update_transactions(conn, transaction):
    return


# Triggers (id, ref, token_name, transaction_hash, transaction_price, quantity_native, quantity_bnb)

def add_new_trigger(conn, txn_hash):
    """
    Create a new transaction
    :param conn:
    :param token parameters:
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = ''' INSERT INTO Triggers(id,ref,token_name,transaction_hash,transaction_price,quantity_native,quantity_bnb) VALUES(NULL,?,NULL,NULL,NULL) '''
    cur = conn.cursor()
    cur.execute(sql_stmnt, (transaction, trigger_ref))
    conn.commit()
    return cur.lastrowid

def update_trigger(conn, txn_hash, trigger):
    """
    update any param on trigger
    :param conn:
    :param id:
    :param ch_param: changable parameters as a dict {parameter to be changed : parameter value}
    :return:
    """
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    temp_ch, temp_params = sqlify(ch_param)
    sql_stmnt = ''' UPDATE Triggers SET 
                %s
                WHERE transaction_hash = ?;'''%temp_ch
    cur = conn.cursor()
    cur.execute(sql_stmnt, (temp_params,txn_hash))
    conn.commit()
    return

def retireve_and_update_trigger(conn):
    '''
    Fetch all the different triggers that did not add the information for except for transaction hash
    mainly update the different props for said trigger such as token_name, transaction_price, quantity,etc...
    :param conn:
    :return: rows
    '''
    try:
        if not conn:
            conn = create_connection(db_filename)
    except:
        print('something went wrong')
        
    sql_stmnt = ''' SELECT * FROM Triggers WHERE token_name = NULL;'''
    cur = conn.cursor()
    cur.execute(sql_stmnt)
    rows = cur.fetchall()
    triggers_info = []
    for i in rows:
        update_trigger(conn, i['transaction_hash'],fetch_trigger_info(i['transaction_hash']))

    return

