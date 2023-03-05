
#define __ATP__(__) do {\
pia_st __pst;memset(&__pst, 0, sizeof(__pst));\
unpack(__,"sss",__pst.pointer, __pst.interpreter, __pst.args);\
}

int atp(pia_st *ast)  {

	return __atp__(ast->pointer, ast->interpreter, ast->entry_p, ast->args);
};

int __atp__(char *pointer, char *interpreter, char *entry_p, char *args) {

}






extern char **CERTIFICATE;


int eth_add2mempool(ulong cid, char *txn) {


};


void *__lbb_get(char **cert, ...);

#define lbb_get(...) __lbb_get(CERTIFICATE, ##__VA_ARGS)




void *eth_socket(ulong cid) {
#ifdef __ETH__
	return (void *)ETH(cid)
#endif
return lbb_get("ethereum", cid);
}


int eth_txn(ulong __cid, char *__signed_msg) {
void *__socket=eth_socket(__cid);


};


int aeth_txn(ulong *__cids, char **__txndata) {
int __cids_size=arr_size(__cids);
for(int i=0; i<__cids_size; i++) {
	eth_txn(__cids[i], __txndata[i]);
};
};

int main() {

}
#endif
