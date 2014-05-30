#ifndef BMMESSAGE_H
#define BMMESSAGE_H

class QByteArray;

class BmMessage
{
private:
    QByteArray* mData; /*!< This message data. */
//        std::set<DmDevice*> mListDevice; /*!< This message associated device. */

public:
    BmMessage( QByteArray* aData, int );
    virtual ~BmMessage();
    QByteArray* getData();
};

#endif // BMMESSAGE_H
