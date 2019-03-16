// Copyright (c) 2016-2017 The Bitzeny Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITZENY_QT_TEST_RPC_NESTED_TESTS_H
#define BITZENY_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

#include <txdb.h>
#include <txmempool.h>

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();
};

#endif // BITZENY_QT_TEST_RPC_NESTED_TESTS_H
