#include "JobScheduler.h"

namespace sf1r
{

JobScheduler::JobScheduler()
{
    asynchronousWorker_ = boost::thread(
        &JobScheduler::runAsynchronousTasks_, this
    );
}

JobScheduler::~JobScheduler()
{
    close();
}

void JobScheduler::close()
{
    asynchronousWorker_.interrupt();
    asynchronousWorker_.join();
}

void JobScheduler::removeTask(const std::string& collection)
{
    if (collection != runCollectionName_)
    {
        asynchronousTasks_.remove_if(RemoveTaskPred(collection));
    }
    else
    {
        close();
        asynchronousTasks_.remove_if(RemoveTaskPred(collection));
        asynchronousWorker_ = boost::thread(
                &JobScheduler::runAsynchronousTasks_, this
        );
    }
}

void JobScheduler::addTask(task_type task, const std::string& collection)
{
    task_collection_name_type taskCollectionPair(task, collection);
    asynchronousTasks_.push(taskCollectionPair);
}

void JobScheduler::setCapacity(std::size_t capacity)
{
    asynchronousTasks_.resize(capacity);
}

void JobScheduler::runAsynchronousTasks_()
{
    try
    {
        task_collection_name_type taskCollectionPair;
        while (true)
        {
            asynchronousTasks_.pop(taskCollectionPair);

            runCollectionName_ = taskCollectionPair.second;
            (taskCollectionPair.first)();
            runCollectionName_.clear();

            // terminate execution if interrupted
            boost::this_thread::interruption_point();
        }
    }
    catch (boost::thread_interrupted&)
    {
        return;
    }
}

}
