// Copyright (c) 2011-2014 The Bitzeny Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITZENY_QT_BITZENYADDRESSVALIDATOR_H
#define BITZENY_QT_BITZENYADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitzenyAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitzenyAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Bitzeny address widget validator, checks for a valid bitzeny address.
 */
class BitzenyAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitzenyAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITZENY_QT_BITZENYADDRESSVALIDATOR_H
