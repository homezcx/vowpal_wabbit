#include <stdio.h>
#include <chrono>
#include <iostream>
#include "./generated/RankingEvent_generated.h"
#include "./generated/OutcomeEvent_generated.h"
#include "../reinforcement_learning/rlclientlib/utility/data_buffer.h"

using VW::Events::RankingEvent;
using VW::Events::OutcomeEvent;
namespace chrono = std::chrono;
#define NUMBER_OF_TEST 1000
#define BUFFER_SIZE 10000000
#define FLAT_BUFFER_INITIAL_SIZE 800000

void serialize_ranking_flatbuffer_message() {

  short version = 1;
  const char* event_id = "test-t1-n10-f10-a2-0-1";
  std::vector<uint64_t> a;
  a.push_back(1);
  a.push_back(2);
  const char* context = "{\"GUser\":{\"f_int\":1,\"f_float\":1.5,\"f_str_0\":\"value_1\",\"f_str_1\":\"value_2\",\"f_str_2\":\"value_3\",\"f_str_3\":\"value_4\",\"f_str_4\":\"value_5\",\"f_str_5\":\"value_6\",\"f_str_6\":\"value_7\",\"f_str_7\":\"value_8\",\"f_str_8\":\"value_9\",\"f_str_9\":\"value_10\"},\"_multi\":[{\"TAction\":{\"a_f_0\":\"value_1\",\"a_f_1\":\"value_2\",\"a_f_2\":\"value_3\",\"a_f_3\":\"value_4\",\"a_f_4\":\"value_5\",\"a_f_5\":\"value_6\",\"a_f_6\":\"value_7\",\"a_f_7\":\"value_8\",\"a_f_8\":\"value_9\",\"a_f_9\":\"value_10\"}},{\"TAction\":{\"a_f_0\":\"value_2\",\"a_f_1\":\"value_3\",\"a_f_2\":\"value_4\",\"a_f_3\":\"value_5\",\"a_f_4\":\"value_6\",\"a_f_5\":\"value_7\",\"a_f_6\":\"value_8\",\"a_f_7\":\"value_9\",\"a_f_8\":\"value_10\",\"a_f_9\":\"value_11\"}}]}";
  std::vector<float> p;
  p.push_back(0.5f);
  p.push_back(0.5f);
  const char* _model_id = "N/A";

  reinforcement_learning::utility::data_buffer buffer;
  buffer.reserve(BUFFER_SIZE);

  flatbuffers::FlatBufferBuilder builder(FLAT_BUFFER_INITIAL_SIZE);

  // test start
  const auto choose_rank_start = std::chrono::high_resolution_clock::now();
  std::vector<flatbuffers::Offset<RankingEvent>> events_offset;
  for (int i = 0; i < NUMBER_OF_TEST; i++) {
    auto event_id_offset = builder.CreateString(event_id);

    auto a_vector_offset = builder.CreateVector(a);
    auto p_vector_offset = builder.CreateVector(p);

    auto context_offset = builder.CreateString(context);

    auto vw_state_offset = VW::Events::CreateVWStateType(builder, builder.CreateString(_model_id));

    events_offset.push_back(VW::Events::CreateRankingEvent(builder, version, event_id_offset, a_vector_offset, context_offset, p_vector_offset, vw_state_offset));
  }
  auto events_vector_offset = builder.CreateVector(events_offset);
  VW::Events::RankingEventBatchBuilder ranking_event_batch_builder(builder);
  ranking_event_batch_builder.add_Events(events_vector_offset);
  auto orc = ranking_event_batch_builder.Finish();
  builder.Finish(orc);
  buffer.append((char*)builder.GetBufferPointer(), builder.GetSize());
  //test end
  const auto choose_rank_end = std::chrono::high_resolution_clock::now();
  std::cout << NUMBER_OF_TEST << " serialize_ranking_flatbuffer_message tests cost " << chrono::duration_cast<chrono::microseconds>(choose_rank_end - choose_rank_start).count() << " microseconds" << std::endl;
}

void serialize_outcome_flatbuffer_message() {
  const char* event_id = "test-t1-n10-f10-a2-0-1";
  const char* outcome = "{\"EventId\":\"test-t1-n10-f10-a2-0-0\",\"v\":{\"Reward\":0,\"CustomRewardField\":1}}";

  reinforcement_learning::utility::data_buffer buffer;
  buffer.reserve(BUFFER_SIZE);

  flatbuffers::FlatBufferBuilder builder(FLAT_BUFFER_INITIAL_SIZE);
  const auto outcome_start = std::chrono::high_resolution_clock::now();
  // test start
  std::vector<flatbuffers::Offset<OutcomeEvent>> events_offset;
  for (int i = 0; i < NUMBER_OF_TEST; i++) {
    auto event_id_offset = builder.CreateString(event_id);
    auto outcome_offset = builder.CreateString(outcome);
    events_offset.push_back(VW::Events::CreateOutcomeEvent(builder, event_id_offset, outcome_offset));
  }

  auto events_vector_offset = builder.CreateVector(events_offset);
  VW::Events::OutcomeEventBatchBuilder outcome_event_batch_builder(builder);
  outcome_event_batch_builder.add_Events(events_vector_offset);
  auto orc = outcome_event_batch_builder.Finish();
  builder.Finish(orc);
  buffer.append((char*)builder.GetBufferPointer(), builder.GetSize());
  // test end
  const auto outcome_end = std::chrono::high_resolution_clock::now();
  std::cout << NUMBER_OF_TEST << " serialize_outcome_flatbuffer_message tests cost " << chrono::duration_cast<chrono::microseconds>(outcome_end - outcome_start).count() << " microseconds" << std::endl;
}

void serialize_ranking_jsonstring() {

  short version = 1;
  const char* event_id = "test-t1-n10-f10-a2-0-1";
  std::vector<uint64_t> a;
  a.push_back(1);
  a.push_back(2);
  const char* context = "{\"GUser\":{\"f_int\":1,\"f_float\":1.5,\"f_str_0\":\"value_1\",\"f_str_1\":\"value_2\",\"f_str_2\":\"value_3\",\"f_str_3\":\"value_4\",\"f_str_4\":\"value_5\",\"f_str_5\":\"value_6\",\"f_str_6\":\"value_7\",\"f_str_7\":\"value_8\",\"f_str_8\":\"value_9\",\"f_str_9\":\"value_10\"},\"_multi\":[{\"TAction\":{\"a_f_0\":\"value_1\",\"a_f_1\":\"value_2\",\"a_f_2\":\"value_3\",\"a_f_3\":\"value_4\",\"a_f_4\":\"value_5\",\"a_f_5\":\"value_6\",\"a_f_6\":\"value_7\",\"a_f_7\":\"value_8\",\"a_f_8\":\"value_9\",\"a_f_9\":\"value_10\"}},{\"TAction\":{\"a_f_0\":\"value_2\",\"a_f_1\":\"value_3\",\"a_f_2\":\"value_4\",\"a_f_3\":\"value_5\",\"a_f_4\":\"value_6\",\"a_f_5\":\"value_7\",\"a_f_6\":\"value_8\",\"a_f_7\":\"value_9\",\"a_f_8\":\"value_10\",\"a_f_9\":\"value_11\"}}]}";
  std::vector<float> p;
  p.push_back(0.5f);
  p.push_back(0.5f);
  const char* _model_id = "N/A";

  reinforcement_learning::utility::data_buffer buffer;
  buffer.reserve(BUFFER_SIZE);

  const auto choose_rank_start = std::chrono::high_resolution_clock::now();
  // test start
  for (int i = 0; i < NUMBER_OF_TEST; i++) {
    //add version and eventId
    buffer << R"({"Version":"1","EventId":")" << event_id;

    //add action ids
    buffer << R"(","a":[)";
    for (auto const &r : a) {
      buffer << r + 1 << ",";
    }
    buffer.remove_last();//remove trailing ,

    //add probabilities
    buffer << R"(],"c":)" << context << R"(,"p":[)";
    for (auto const &r : p) {
      buffer << r << ",";
    }
    buffer.remove_last();//remove trailing ,

    //add model id
    buffer << R"(],"VWState":{"m":")" << _model_id << R"("})";
  }
  // test end
  const auto choose_rank_end = std::chrono::high_resolution_clock::now();
  std::cout << NUMBER_OF_TEST << " serialize_ranking_jsonstring tests cost " << chrono::duration_cast<chrono::microseconds>(choose_rank_end - choose_rank_start).count() << " microseconds" << std::endl;
}

void serialize_outcome_jsonstring() {
  const char* event_id = "test-t1-n10-f10-a2-0-1";
  const char* outcome = "{\"EventId\":\"test-t1-n10-f10-a2-0-0\",\"v\":{\"Reward\":0,\"CustomRewardField\":1}}";
  reinforcement_learning::utility::data_buffer buffer;
  buffer.reserve(BUFFER_SIZE);

  const auto outcome_start = std::chrono::high_resolution_clock::now();
  // test start
  for (int i = 0; i < NUMBER_OF_TEST; i++) {
    buffer << R"({"EventId":")" << event_id << R"(","v":)" << outcome << R"(})";
  }
  // test end
  const auto outcome_end = std::chrono::high_resolution_clock::now();
  std::cout << NUMBER_OF_TEST << " serialize_outcome_jsonstring tests cost " << chrono::duration_cast<chrono::microseconds>(outcome_end - outcome_start).count() << " microseconds" << std::endl;
}

void main() {
  printf("test start...\n");
  serialize_ranking_flatbuffer_message();
  serialize_ranking_jsonstring();
  serialize_outcome_flatbuffer_message();
  serialize_outcome_jsonstring();
  printf("test end...\n");
  getchar();
}
