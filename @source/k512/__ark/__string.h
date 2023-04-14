

/************************ d-strings ************************/

#ifndef _D_STRING
	#define _D_STRING 1

	int __nullchar(char __c) {
		if(__c==0x00) {
			return 1;
		};
		return 0;
	};

	int __numchar(char __c){   
		// check if char is a number
		if( (__c>=0x30)&&(__c<=0x39)){
			return 1;
		};
		return 0;
	};

	int __smchar(char __c) {
		// check if char is a small cap alphabet
		if((__c>=0x61)&&(__c<=0x7a)){
			return 1;
		};
		return 0;
	};

	int __capchar(char __c) {
		// check if char is a large cap alphabet
		if((__c>=0x41)&&(__c<=0x5a)){
			return 1;
		};
		return 0;
	};

	int __atchar(char __c) {
		// check if char is an '@' character
		if(__c==0x40){
			return 1;
		};
		return 0;
	};

	int __sepchar(char __c) {
		if(__c==0x3a) {
			return 1;
		};
		return 0;
	};

	int __delimchar(char __c) {
		if(__c==*__os_delim) {
			return 1;
		};
		return 0;
	};

	ulong __rwings(void const *__) {
		char const *__p=(char const *)__;
		ulong __c=0;
		do {
			if(*__p!='\0'){
				__c+=1;
			};
		}while(*__p++);
		return __c;
	};

	ulong str_rwings(char const *__str) {
		ulong temp=0;
		if(__str!=NULL){
			do {
				if(*__str=='\0'){
					break;
				};
				temp+=1;
			}while((*__str++)&&(temp<4096));
		};
		#ifdef DEBUG
			printf("str : %s =: %lu\n",(char const *)(__str-temp),temp);
		#endif
		return temp;
	};

	int spaces_and_tabs(char *__word){
		/**
		 * count spaces and tabs in `word`
		**/
		int count=0, x=0;
		while(__word[x]!='\0'){
			if(__word[x]==' '||__word[x]==' '){
				count+=1;
			};
			x+=1;
		};
		return count;
	};

	int tabs_and_spaces(char const *__word){
		/**
		 * count spaces and tabs until `word`
		**/
		int count=0;
		while(__word[count]==' '||__word[count]==' '){
			count+=1;
		};
		return count;	
	};

	ulong __tonum(char const *__var){
		ulong d=1,__c=0,res=0,__len=str_rwings(__var);
		int c;
		if(__var[__len]=='\0'){
			while(__numchar(__var[__c])){
				d*=10;
				__c+=1;
			};
			__c=0;
			if(d>=10){d/=10;}
			#ifdef DDEBUG
				printf("digits count :: %lu\n",d);
			#endif
			while(__numchar(__var[__c])){
				res+=(d*(__var[__c]-0x30));
				__c+=1;d/=10;
			}
			#ifdef DDEBUG
				printf("result is :: %lu\n", res);
			#endif
		};
		return res;
	};

	ulong tonum(int __i){
		ulong res=0;
		if(__i>0){
			res+=__i;
			return res;
		};
		return 0;
	};

	char const *num2char(ulong snum_in){
		char __[21];
		memset(&__,0,sizeof(__));
		sprintf(__,"%lu",snum_in);
		return (char const *)strdup(__);
	};

	char const *s_num2char(long snum_in) {
		char __[21];
		memset(&__, 0, sizeof(__));
		if(snum_in>0) {
			sprintf(__, "+%lu", snum_in);
		}
		else {
			sprintf(__, "-%lu", snum_in);
		};

		return (char const *) strdup(__);
	};

	char *__stn(char const *__word, ulong __len) {
		ulong rc=0, c=0;
		char temp[__len];memset(&temp, 0, sizeof(__word));
		do {
			if((__word[c]==' ')||(__word[c]=='	')||(__word[c]=='\n')){
				c+=1;
			}
			else {
				temp[rc]=__word[c];
				rc+=1;c+=1;
			};
		}while(c<=__len);
		temp[rc]='\0';
		return strdup(temp);
	};

	void *__arg__(char const *fc) {
		int tas=tabs_and_spaces(fc);
		printf("Arg : %c\n",*(fc+1));
		if(*(fc+1)=='"'){
			return "string";
		};
		return "n";
	};
	
	int __exact_match(char const *__a, char const *__b) {
		ulong __alen=str_rwings(__a), __blen=str_rwings(__b);
		if (__alen!=__blen) {
			#ifdef DEBUG
				printf("A&B lengths do not match\n");
			#endif
			return 0;
		};
		while(--__alen!=0) {
			if(__a[__alen]==__b[__alen]){
				continue;
			}else {
				return 0;
			};
		};
		return 1;
	};

	int __sep_atoff(char const *string, char const *seperator) {
		/**
		 * find the first `seperator` in `string`
		**/
		long x=0,y=0,len_count=0,offset_at=-1;
		while(string[x]!='\0'){
			if(string[x]==seperator[y]){
				while(seperator[y]==string[y+x]){
					y+=1;
				};
				if(seperator[y]=='\0'){
					offset_at=x;
				}
				else{
					y=0;
				};
			};
			x+=1;
		};
		if(offset_at==-1){
			return -1;
		};
		return offset_at;
	};

	char *str_b4eoffset(char const *string, ulong offset) {
		char temp[offset];
		memset(&temp,0,sizeof temp);
		memmove(temp, ++string, offset-2);
		return strdup(temp);
	};

	char *str_b4offset(char const *string, ulong offset) {
		char temp[offset];
		memset(&temp,0,sizeof temp);
		snprintf(temp,offset,"%s",string);
		return strdup(temp);
	};

	char *stn_b4offset(char const *string, ulong offset) {

		return __stn(string, offset);
	};

	char *str_a4woffset(char const *string, ulong offset){
		ulong flen=str_rwings(string);//to offset the offset 
		if(flen<offset){return NULL;}
		ulong slen=flen-offset;
		char temp[slen];
		memset(&temp,0,sizeof temp);
		snprintf(temp,slen,"%s",(string+offset));
		return strdup(temp);
	};

	char *str_a4offset(char const *string, ulong offset){
		ulong flen=str_rwings(string)+1;//to offset the offset 
		if(flen<offset){return NULL;}
		ulong slen=flen-offset;
		char temp[slen];
		memset(&temp,0,sizeof temp);
		snprintf(temp,slen,"%s",(string+offset));
		return strdup(temp);
	};

	char const *expand_atoffset(char const *__str, char const *expantion, ulong __offset) {
		#ifdef DEBUG
			printf("@index:%lu\n", __offset);
		#endif
		ulong __str_rwings=str_rwings(__str);
		ulong __explen=str_rwings(expantion);
		ulong __len=__str_rwings+__explen+1;
		char __[__len];memset(&__, 0, sizeof(__));
		memmove(__, __str, __offset);
		memmove((__+__offset), expantion, __explen);
		memmove((__+__offset+__explen), (__str+__offset+1), (__str_rwings-__offset));
		return (char const *)strdup(__);
	};

	char const *expand(char const *__str, char const *expantion, ulong __offset) {
		ulong __strlen=str_rwings(__str);
		ulong __explen=str_rwings(expantion);
		ulong __len=__strlen+__explen+1;
		char __[__len];memset(&__, 0, sizeof(__));
		memmove(__, __str, __offset);
		memmove((__+__offset), expantion, __explen);
		memmove((__+__offset+__explen), (__str+__offset), (__strlen-__offset));
		return (char const *)strdup(__);
	};

	char const *__expand_str(char const *__str, char const *__expantion) {

		return expand(__str, __expantion, str_rwings(__str));
	}

	char const *__combine_str(char const *str1, char const *str2) {
		ulong _lstr1=str_rwings(str1),_lstr2=str_rwings(str2);
		ulong __len=_lstr1+_lstr2+1;
		char __[__len], *__p=(char *)&__;
		memset(__p, 0, sizeof(__));
		__[__len]='\0';
		memmove(__p, str1, _lstr1);
		memmove((__p+_lstr1), str2, _lstr2);
		return strdup(__);
	};

	ulong str_cdelims(char const *__str, char const *__dlm) {
		ulong count=0, temp=0, length=str_rwings(__str);
		char *substr=(char *)__str;
		d_str *subs;		
		while((temp=__sep_atoff(substr, __dlm))>=1) {
			if(!count){
				count=1;
				subs=(d_str*)malloc(sizeof(d_str));
				subs->__=str_a4offset(substr, temp);
				subs->__len=str_rwings(substr);
				subs->__next=NULL;
			}
			else if (count) {
				count+=1;
				substr=str_a4offset(substr, temp);
				++substr;subs++;
				printf("type     :%c: %s\n\n",*substr, (char *)__arg__(substr));
					// string(temp, substr)
				// subs->__next=&temp;
			}else {
			
			};
		};
		return count;
	};

	ulong arr_cdelims(char const *__str) {
		// add 1 more to create an array
		// #err if more elements than arg_count specifies
		ulong arg_count=str_cdelims(__str, ARR_DELIM)+1;
		return arg_count;
	};

	ulong sep_offset(char const *string, char *seperator) {
		#ifdef DEBUG
			printf("string : %s\n", string);
		#endif
		int tempres=__sep_atoff(string, seperator);
		if(tempres==-1){
			#ifdef LOG_ERR
				printf("unsigned call\n");
				printf("%s <%s?>", string, seperator);
				_exit(1);
				// #error "should not return"
			#endif
			return 0;
		}
		else if (!tempres) {
			return 0;
		} else {
			return (ulong)tempres;
		};
	};
#endif


