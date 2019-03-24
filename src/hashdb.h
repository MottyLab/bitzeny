#ifndef BITZENY_HASHDB_H
#define BITZENY_HASHDB_H

#include <dbwrapper.h>
#include <primitives/block.h>
#include <uint256.h>

/** Access to the hash database (hashes/) */
class CHashDB : public CDBWrapper
{
public:
    CHashDB(size_t nCacheSize, bool fMemory = false, bool fWipe = false);
    uint256 GetHashDB(const CBlockHeader& block);
};

extern CHashDB *phashdb;

#endif //BITZENY_HASHDB_H
