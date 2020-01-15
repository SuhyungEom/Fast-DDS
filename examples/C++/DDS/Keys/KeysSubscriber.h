// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file KeysSubscriber.h
 *
 */

#ifndef KEYSSUBSCRIBER_H_
#define KEYSSUBSCRIBER_H_

#include "samplePubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/core/status/SubscriptionMatchedStatus.hpp>
#include <fastdds/dds/core/status/IncompatibleQosStatus.hpp>

class KeysSubscriber
{
public:

    KeysSubscriber();

    virtual ~KeysSubscriber();

    //!Initialize the subscriber
    bool init(
            int domain_id);

    //!RUN the subscriber
    void run();

    //!Run the subscriber until number samples have been recevied.
    void run(
            uint32_t number);

private:

    eprosima::fastdds::dds::DomainParticipant* participant_;

    eprosima::fastdds::dds::Subscriber* subscriber_;

    eprosima::fastdds::dds::DataReader* reader_;

    eprosima::fastdds::dds::TypeSupport type_;

    class SubListener : public eprosima::fastdds::dds::DomainParticipantListener
    {
public:

        SubListener()
            : matched_(0)
            , samples_(0)
        {
        }

        ~SubListener() override
        {
        }

        void on_data_available(
                eprosima::fastdds::dds::DataReader* reader) override;

        void on_subscription_matched(
                eprosima::fastdds::dds::DataReader* reader,
                const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

        sample hello_;

        eprosima::fastdds::dds::SampleInfo_t info_;

        int matched_;

        uint32_t samples_;

        bool enable_ = true;
    } listener_;
};

#endif /* KEYSSUBSCRIBER_H_ */