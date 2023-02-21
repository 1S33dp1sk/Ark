/// The d-cloud \\\
The D-cloud is a Layer-3 network

#include "2c/_h512.h"
#include "2c/ixr.h"


char *__pre_apple="/Users/mrkj/package/";
char *__pre_unix="/home/mrkj/package";
char *__pre_wind="C:\\package\\mrkj";


char *__pre_="///mrkj\\\\";
char const *mount_at="@charms/lbb/index.ext";
char const *_socket_="22ef791c@0.0.0.0";
char const *_forward_addr="@mrkj";
char const *_backward_addr="25258931ae931139141";
char const *k_addr="mrkj@25258931ae9311739141";




// __TEXT(Hello World); //valid in ATP

int main(int argc, char **argv) {

	m_stat mstat;
	int res=get_mstat(mount_at,&mstat);
	// printf("get mstat res=%d\n",res);
	// log_mstat(&mstat);

	s_stat sstat;
	res=get_sstat(_socket_,&sstat);
	// printf("get sstat res=%d\n",res);
	// log_sstat(&sstat);

	k_stat kstat;
	res=get_kstat(k_addr,&kstat);
	// printf("get kstat res=%d\n",res);
	// log_kstat(&kstat);


	


	



	return 0;

}