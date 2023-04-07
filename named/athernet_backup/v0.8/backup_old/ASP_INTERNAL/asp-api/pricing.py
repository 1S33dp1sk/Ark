import sqlite3
from misc import dict_factory


def priceit(partnumber, designation, brand, quantity):
    conn = sqlite3.connect('/home/kj/Desktop/.d/ASP_INTERNAL/databases/parts.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    query = 'SELECT price,quantity FROM stock WHERE partnumber=? AND designation=? AND brand=?;'
    to_filter = [partnumber, designation, brand]
    results = cur.execute(query, to_filter).fetchall()
    conn.close()

    for x in results:
        x['price'] = str(int(x['price'])*1.78)
        if int(x['quantity']) > int(quantity):
            x['quantity'] = quantity
    if len(results) > 0:
        return results
    else:
        return False    
