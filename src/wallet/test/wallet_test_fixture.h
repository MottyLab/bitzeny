// Copyright (c) 2016-2017 The Bitzeny Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITZENY_WALLET_TEST_FIXTURE_H
#define BITZENY_WALLET_TEST_FIXTURE_H

#include <test/test_bitzeny.h>

#include <wallet/wallet.h>

#include <memory>

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    explicit WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();

    std::unique_ptr<CWallet> pwalletMain;
};

#endif

