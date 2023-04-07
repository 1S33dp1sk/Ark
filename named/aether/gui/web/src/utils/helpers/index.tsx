import { toast } from 'react-toastify';


export const notify = (type:string, notify:string) => {
  switch (type) {
    case 'info':
      toast.info(`INFO :: ${notify}`);
      break;
    case 'success':
      toast.success(`SUCCESSFULY :: ${notify}`);
      break;
    case 'warn':
      toast.warn(`WARNING :: ${notify}`);
      break;
    case 'error':
      toast.error(`ERROR :: ${notify}`);
      break;
  }
};
export const validateNumber = (event:any) => {
    const keyCode = event.keyCode;

    const excludedKeys = [8, 37, 39, 46,190,110];

    if (!( (keyCode >= 48 && keyCode <= 57) || (keyCode >= 96 && keyCode <= 105) || (excludedKeys.includes(keyCode)) )) {
      event.preventDefault();
    }
};
export function isNumber(val:string){
    let isnum = /^\d+$/.test(val);
    if (isnum) {
      return true
    }
    return false;
};
export function walletAddress(account: any) {
    if (account) {
      const address = account.split("");
      return (
        address[0] +
        address[1] +
        address[2] +
        address[3] +
        "..." +
        address[38] +
        address[39] +
        address[40] +
        address[41]
      );
    }
    return "Connect Wallet";
};
export function toggleVar(id: string) {
  var _v = document.getElementById(id);
  if (_v?.className === "") {
    _v.className += "dv";
  } else {
    _v!.className = "";
  }
};
export function getTotality(var_num:number,id:number){
  let _temp: any = [];
    if (id) {
      _temp.push(id);
    } else {
      for (let i = var_num; i > var_num - 5; i--) {
        if (i >= 0) {
          _temp.push(i);
        }
      }
    }
    return _temp
};
export const filtration = (keyword: string, list:any) => {
  const _temp = list;
  if (keyword !== "") {
    const _vars = list.filter((val:any) => {
      return val.address.toLowerCase().includes(keyword.toLowerCase());
    });

    return _vars;
  } else {
    return _temp;
  }
};
export function openMenu() {
  var menu = document.getElementById("ch-menu");
  if (menu?.className === "ch-menu") {
    menu!.className += " open";
  } else {
    menu!.className = "ch-menu";
  }
};
export function copyData(data:any) {
    return navigator.clipboard.writeText(data);
};


