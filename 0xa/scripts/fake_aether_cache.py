import os
from aether.tru import Dynamic,Aether
_path = '/home/kj/Aether/client/Aether/nodes/DEFAULT.node/cache.json'
d = Dynamic(_path)
a = Aether()
block = a.Block('0xcb6af5efea3f2f7ef6afba8ecd8f0e7a0fcd32d505bdf05a14d914e3acee7a9d',15,[],'0xaaacfb3b0f818f72b402dbdbfaebd17cf10afbca')

d.add_to_cache( block=block )

status = a.Status([241041,1204102,123124,1241241,124124],12141,[1,2,3,4,5],'0xcb6af5efea3f2f7ef6afba8ecd8f0e7a0fcd32d505bdf05a14d914e3acee7a9d','0xaaacfb3b0f818f72b402dbdbfaebd17cf10afbca',3)

d.add_to_cache( status=status )


txn = a.Transaction([1,2,3,4,5],'0xcc4a82b2d5acb2abeaaddfbe6d3cf1ce34ad9d74','0xe23d0c9ab5f38e9e21ed9cbbbfabed23c573f6eb','0xb70102ae','0x',1,3)
txn2 = a.Transaction([1,2,3],'0xe23d0c9ab5f38e9e21ed9cbbbfabed23c573f6eb','0xaaacfb3b0f818f72b402dbdbfaebd17cf10afbca','0xb70102ae','0x',3,3)
txn3 = a.Transaction([1,2,3],'0xcc4a82b2d5acb2abeaaddfbe6d3cf1ce34ad9d74','0xaaacfb3b0f818f72b402dbdbfaebd17cf10afbca','0xb70102ae','0x',3,3)
txn4 = a.Transaction([1,2,3],'0xcc4a82b2d5acb2abeaaddfbe6d3cf1ce34ad9d74','0xe23d0c9ab5f38e9e21ed9cbbbfabed23c573f6eb','0xb70102ae','0x',4,3)
txn5 = a.Transaction([1,2,3],'0xe23d0c9ab5f38e9e21ed9cbbbfabed23c573f6eb','0xcc4a82b2d5acb2abeaaddfbe6d3cf1ce34ad9d74','0xb70102ae','0x',2,3)
txn6 = a.Transaction([1,2,3,4,5],'0xe23d0c9ab5f38e9e21ed9cbbbfabed23c573f6eb','0xcc4a82b2d5acb2abeaaddfbe6d3cf1ce34ad9d74','0xb70102ae','0x',5,3)

d.add_to_cache(txn)
d.add_to_cache(txn2)
d.add_to_cache(txn3)
d.add_to_cache(txn4)
d.add_to_cache(txn5)
d.add_to_cache(txn6)
