//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


library StorageSlot {
    struct AddressSlot {
        address value;
    }

	struct BooleanSlot {
        bool value;
    }

    function getAddressSlot(bytes32 slot) internal pure returns (AddressSlot storage r) {
        assembly {
            r.slot := slot
        }
    }

    function getBooleanSlot(bytes32 slot) internal pure returns (BooleanSlot storage r) {
        assembly {
            r.slot := slot
        }
    }

}