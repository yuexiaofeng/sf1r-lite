#ifndef INDEX_BUNDLE_ACTIVATOR_H
#define INDEX_BUNDLE_ACTIVATOR_H

#include "IndexSearchService.h"
#include "IndexTaskService.h"

#include <common/type_defs.h>


#include <util/osgi/IBundleActivator.h>
#include <util/osgi/IBundleContext.h>
#include <util/osgi/IServiceRegistration.h>
#include <util/osgi/ServiceTracker.h>

#include <boost/shared_ptr.hpp>

namespace sf1r
{
using namespace izenelib::osgi;

class IndexManager;
class DocumentManager;
class LAManager;
class SearchManager;
class RankingManager;
class AggregatorManager;

class IndexBundleActivator : public IBundleActivator, public IServiceTrackerCustomizer
{
private:
    ServiceTracker* miningSearchTracker_;
    ServiceTracker* miningTaskTracker_;

    ServiceTracker* recommendSearchTracker_;
    ServiceTracker* recommendTaskTracker_;

    ServiceTracker* productSearchTracker_;
    ServiceTracker* productTaskTracker_;

    IBundleContext* context_;
    IndexSearchService* searchService_;
    IServiceRegistration* searchServiceReg_;
    IndexTaskService* taskService_;
    IServiceRegistration* taskServiceReg_;

    IndexBundleConfiguration* config_;
    std::string currentCollectionDataName_;

    boost::shared_ptr<LAManager> laManager_;
    boost::shared_ptr<IDManager> idManager_;
    boost::shared_ptr<DocumentManager> documentManager_;
    boost::shared_ptr<IndexManager> indexManager_;
    boost::shared_ptr<RankingManager> rankingManager_;
    boost::shared_ptr<SearchManager> searchManager_;
    boost::shared_ptr<WorkerService> workerService_;
    boost::shared_ptr<AggregatorManager> aggregatorManager_;
    ilplib::qa::QuestionAnalysis* pQA_;
    DirectoryRotator directoryRotator_;

    bool init_();

    bool openDataDirectories_();

    boost::shared_ptr<IDManager>
    createIDManager_() const;

    boost::shared_ptr<DocumentManager>
    createDocumentManager_() const;

    boost::shared_ptr<IndexManager>
    createIndexManager_() const;
    
    boost::shared_ptr<RankingManager>
    createRankingManager_() const;

    boost::shared_ptr<SearchManager> createSearchManager_() const;

    boost::shared_ptr<LAManager> createLAManager_() const;

    boost::shared_ptr<WorkerService> createWorkerService_() ;

    boost::shared_ptr<AggregatorManager> createAggregatorManager_() const;

    bool initializeQueryManager_() const;

    std::string getCollectionDataPath_() const;
    
    std::string getCurrentCollectionDataPath_() const;
    
    std::string getQueryDataPath_() const;

public:
    IndexBundleActivator();
    virtual ~IndexBundleActivator();
    virtual void start( IBundleContext::ConstPtr context );
    virtual void stop( IBundleContext::ConstPtr context );
    virtual bool addingService( const ServiceReference& ref );
    virtual void removedService( const ServiceReference& ref );
};

}
#endif

