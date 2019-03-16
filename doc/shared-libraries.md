Shared Libraries
================

## bitzenyconsensus

The purpose of this library is to make the verification functionality that is critical to Bitzeny's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `bitzenyconsensus.h` located in  `src/script/bitzenyconsensus.h`.

#### Version

`bitzenyconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`bitzenyconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `bitzenyconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/bitzeny/bips/blob/master/bip-0016.mediawiki)) subscripts
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/bitzeny/bips/blob/master/bip-0066.mediawiki)) compliance
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/bitzeny/bips/blob/master/bip-0147.mediawiki))
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/bitzeny/bips/blob/master/bip-0065.mediawiki))
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/bitzeny/bips/blob/master/bip-0112.mediawiki))
- `bitzenyconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/bitzeny/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `bitzenyconsensus_ERR_OK` - No errors with input parameters *(see the return value of `bitzenyconsensus_verify_script` for the verification status)*
- `bitzenyconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `bitzenyconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `bitzenyconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `bitzenyconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NBitzeny](https://github.com/NicolasDorier/NBitzeny/blob/master/NBitzeny/Script.cs#L814) (.NET Bindings)
- [node-libbitzenyconsensus](https://github.com/bitpay/node-libbitzenyconsensus) (Node.js Bindings)
- [java-libbitzenyconsensus](https://github.com/dexX7/java-libbitzenyconsensus) (Java Bindings)
- [bitzenyconsensus-php](https://github.com/Bit-Wasp/bitzenyconsensus-php) (PHP Bindings)
