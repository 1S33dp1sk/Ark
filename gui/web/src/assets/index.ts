// WALLETS
import metamask from './icons/metamask.png';
import walletconnect from './icons/walletconnect.png';
// ICONS
import aether from './icons/aether.svg';
import A from './icons/A.svg';
import qm from './icons/qm.svg';
import w_logo from './images/w_logo.svg';
import b_logo from './images/b_logo.svg';
import arrow from './icons/arrow.svg';
import l_arr from './icons/l_arr.svg';
import r_arr from './icons/r_arr.svg';
import athr_blk from './icons/the_aether_black.svg';
import athr_wht from './icons/the_aether_white.svg';
import r_arrw from './icons/r_arrw.svg';
import l_arrw from './icons/l_arrw.svg';
import menu from './icons/menu.svg';
import search from './icons/search.svg';
import close from './icons/close.svg';
import txn from './icons/txn.svg';
import diff from './icons/diff.svg';
import cost from './icons/cost.svg';
import ip from './icons/ip.svg';
import network from './icons/network.svg';
import wallet from './icons/wallet.svg';
import sm_arr from './icons/sm_arr.svg';
import mob_menu from './icons/mob_menu.svg';

// Feature Graph Levels
import sc11 from './levels/TP0.svg';
import sc12 from './levels/TP1.svg';
import sc13 from './levels/TP2.svg';
import sc14 from './levels/TP3.svg';
import sc16 from './levels/TP4.svg';
import sc17 from './levels/TP5.svg';
import b1 from './levels/KP0.svg';
import b2 from './levels/KP1.svg';
import b3 from './levels/KP2.svg';
import b4 from './levels/KP3.svg';
import d1 from './levels/DC0.svg';
import d2 from './levels/DC1.svg';
import d3 from './levels/DC2.svg';

// SOCILA MEDIA
import discord from './icons/discord.svg';
import telegram from './icons/telegram.svg';
import twitter from './icons/twitter.svg';
import github from './icons/github.svg';

// CHAINS LOGOS
import AVAX from './icons/chainslogo/AVAX.svg';
import BSC from './icons/chainslogo/BSC.svg';
import CRO from './icons/chainslogo/CRO.svg';
import ETH from './icons/chainslogo/ETH.svg';
import FTM from './icons/chainslogo/FTM.svg';
import MATIC from './icons/chainslogo/MATIC.svg';

// ---------FOR TEST PURPOSES
import clock from './icons/clock.svg';


// ------------------------------
export const images = {
    w_logo, b_logo
};

export const icons = {
    socials:{
        discord, telegram,twitter, github
    },
    qm,arrow,metamask, walletconnect,
    l_arr, r_arr, A,
    athr_wht, athr_blk, close,
    r_arrw, l_arrw, menu, search, aether, txn, diff,
    cost, ip, network, wallet,clock, sm_arr, mob_menu
};

export const levels = {
    "Transaction Processing":[sc11, sc12, sc13, sc14, sc16, sc17],
    "Index Balancing":[b1, b2, b3, b4],
    "PseudoProxy Deployment":[d1, d2, d3],
};

export const chainsLogo = {AVAX, BSC, CRO, ETH, FTM, MATIC}