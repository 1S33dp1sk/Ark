//SPDX-License-Identifier: GPL v3
pragma solidity ^0.8.0;

interface AetherBasic {
    enum AContractID { AFactory , ARouter , ADAO , AToken , AHUB , AKeeper , ABonds }
}


interface ContextOwner {
    function owner() external view returns(address);
}

