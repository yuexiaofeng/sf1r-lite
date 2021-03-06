#ifndef SF1R_COMMON_NUMERIC_PROPERTY_TABLE_BASE_H
#define SF1R_COMMON_NUMERIC_PROPERTY_TABLE_BASE_H

#include "type_defs.h"
#include "PropSharedLock.h"
#include <boost/thread/shared_mutex.hpp>

namespace sf1r
{

class NumericPropertyTableBase : public PropSharedLock
{
public:
    NumericPropertyTableBase(PropertyDataType type) : type_(type)
    {
    }

    PropertyDataType getType() const
    {
        return type_;
    }

    virtual ~NumericPropertyTableBase() {}

    virtual void init(const std::string& path) = 0;
    virtual void resize(std::size_t size) = 0;
    virtual std::size_t size(bool isLock = true) const = 0;
    virtual void flush() = 0;

    virtual bool isValid(std::size_t pos, bool isLock = true) const { return false; }

    virtual bool getInt32Value(std::size_t pos, int32_t& value, bool isLock = true) const = 0;
    virtual bool getFloatValue(std::size_t pos, float& value, bool isLock = true) const = 0;
    virtual bool getInt64Value(std::size_t pos, int64_t& value, bool isLock = true) const = 0;
    virtual bool getDoubleValue(std::size_t pos, double& value, bool isLock = true) const = 0;

    virtual bool getStringValue(std::size_t pos, std::string& value, bool isLock = true) const = 0;
    virtual bool getDoublePairValue(std::size_t pos, std::pair<double, double>& value, bool isLock = true) const = 0;
    virtual bool getInt64PairValue(std::size_t pos, std::pair<int64_t, int64_t>& value, bool isLock = true) const = 0;

    virtual bool getFloatMinValue(float& minValue, bool isLock = true) const { return false; }
    virtual bool getFloatMaxValue(float& maxValue, bool isLock = true) const { return false; }

    virtual void* getValueList() = 0;
    virtual const void* getValueList() const = 0;

    virtual void setInt32Value(std::size_t pos, const int32_t& value) = 0;
    virtual void setFloatValue(std::size_t pos, const float& value) = 0;
    virtual void setInt64Value(std::size_t pos, const int64_t& value) = 0;
    virtual void setDoubleValue(std::size_t pos, const double& value) = 0;

    virtual bool setStringValue(std::size_t pos, const std::string& value) = 0;

    virtual void copyValue(std::size_t from, std::size_t to) = 0;
    virtual int compareValues(std::size_t lhs, std::size_t rhs, bool isLock = true) const = 0;
    virtual void clearValue(std::size_t pos) = 0;

protected:
    PropertyDataType type_;
};

}

#endif
