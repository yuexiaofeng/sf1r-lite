///
/// @file MiningTask.h
/// @author hongliang.zhao@b5m.com
/// @date Created 2012.11.28
///
#ifndef MINING_TASK_H
#define MINING_TASK_H

#include <document-manager/Document.h>
#include <common/inttypes.h>

//this is for each proprety....
namespace sf1r
{
class MiningTask
{
public:
    MiningTask() {};
    virtual ~MiningTask() {};

    virtual bool buildDocument(docid_t docID, const Document& doc) = 0;

    virtual bool preProcess(int64_t timestamp) = 0;

    virtual bool postProcess() = 0;

    virtual docid_t getLastDocId() = 0;

};
}

#endif
