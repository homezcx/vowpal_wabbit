// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_RANKINGEVENT_VW_EVENTS_H_
#define FLATBUFFERS_GENERATED_RANKINGEVENT_VW_EVENTS_H_

#include "flatbuffers/flatbuffers.h"

namespace VW {
namespace Events {

struct VWStateType;

struct RankingEvent;

struct RankingEventBatch;

struct VWStateType FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_M = 4
  };
  const flatbuffers::String *m() const {
    return GetPointer<const flatbuffers::String *>(VT_M);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_M) &&
           verifier.VerifyString(m()) &&
           verifier.EndTable();
  }
};

struct VWStateTypeBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_m(flatbuffers::Offset<flatbuffers::String> m) {
    fbb_.AddOffset(VWStateType::VT_M, m);
  }
  explicit VWStateTypeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VWStateTypeBuilder &operator=(const VWStateTypeBuilder &);
  flatbuffers::Offset<VWStateType> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<VWStateType>(end);
    return o;
  }
};

inline flatbuffers::Offset<VWStateType> CreateVWStateType(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> m = 0) {
  VWStateTypeBuilder builder_(_fbb);
  builder_.add_m(m);
  return builder_.Finish();
}

inline flatbuffers::Offset<VWStateType> CreateVWStateTypeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *m = nullptr) {
  return VW::Events::CreateVWStateType(
      _fbb,
      m ? _fbb.CreateString(m) : 0);
}

struct RankingEvent FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_VERSION = 4,
    VT_EVENTID = 6,
    VT_A = 8,
    VT_C = 10,
    VT_P = 12,
    VT_VWSTATE = 14
  };
  int16_t Version() const {
    return GetField<int16_t>(VT_VERSION, 1);
  }
  const flatbuffers::String *EventId() const {
    return GetPointer<const flatbuffers::String *>(VT_EVENTID);
  }
  const flatbuffers::Vector<uint64_t> *a() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_A);
  }
  const flatbuffers::String *c() const {
    return GetPointer<const flatbuffers::String *>(VT_C);
  }
  const flatbuffers::Vector<float> *p() const {
    return GetPointer<const flatbuffers::Vector<float> *>(VT_P);
  }
  const VWStateType *VWState() const {
    return GetPointer<const VWStateType *>(VT_VWSTATE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_VERSION) &&
           VerifyOffset(verifier, VT_EVENTID) &&
           verifier.VerifyString(EventId()) &&
           VerifyOffset(verifier, VT_A) &&
           verifier.VerifyVector(a()) &&
           VerifyOffset(verifier, VT_C) &&
           verifier.VerifyString(c()) &&
           VerifyOffset(verifier, VT_P) &&
           verifier.VerifyVector(p()) &&
           VerifyOffset(verifier, VT_VWSTATE) &&
           verifier.VerifyTable(VWState()) &&
           verifier.EndTable();
  }
};

struct RankingEventBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_Version(int16_t Version) {
    fbb_.AddElement<int16_t>(RankingEvent::VT_VERSION, Version, 1);
  }
  void add_EventId(flatbuffers::Offset<flatbuffers::String> EventId) {
    fbb_.AddOffset(RankingEvent::VT_EVENTID, EventId);
  }
  void add_a(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> a) {
    fbb_.AddOffset(RankingEvent::VT_A, a);
  }
  void add_c(flatbuffers::Offset<flatbuffers::String> c) {
    fbb_.AddOffset(RankingEvent::VT_C, c);
  }
  void add_p(flatbuffers::Offset<flatbuffers::Vector<float>> p) {
    fbb_.AddOffset(RankingEvent::VT_P, p);
  }
  void add_VWState(flatbuffers::Offset<VWStateType> VWState) {
    fbb_.AddOffset(RankingEvent::VT_VWSTATE, VWState);
  }
  explicit RankingEventBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RankingEventBuilder &operator=(const RankingEventBuilder &);
  flatbuffers::Offset<RankingEvent> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<RankingEvent>(end);
    return o;
  }
};

inline flatbuffers::Offset<RankingEvent> CreateRankingEvent(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t Version = 1,
    flatbuffers::Offset<flatbuffers::String> EventId = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> a = 0,
    flatbuffers::Offset<flatbuffers::String> c = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> p = 0,
    flatbuffers::Offset<VWStateType> VWState = 0) {
  RankingEventBuilder builder_(_fbb);
  builder_.add_VWState(VWState);
  builder_.add_p(p);
  builder_.add_c(c);
  builder_.add_a(a);
  builder_.add_EventId(EventId);
  builder_.add_Version(Version);
  return builder_.Finish();
}

inline flatbuffers::Offset<RankingEvent> CreateRankingEventDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t Version = 1,
    const char *EventId = nullptr,
    const std::vector<uint64_t> *a = nullptr,
    const char *c = nullptr,
    const std::vector<float> *p = nullptr,
    flatbuffers::Offset<VWStateType> VWState = 0) {
  return VW::Events::CreateRankingEvent(
      _fbb,
      Version,
      EventId ? _fbb.CreateString(EventId) : 0,
      a ? _fbb.CreateVector<uint64_t>(*a) : 0,
      c ? _fbb.CreateString(c) : 0,
      p ? _fbb.CreateVector<float>(*p) : 0,
      VWState);
}

struct RankingEventBatch FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_EVENTS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<RankingEvent>> *Events() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<RankingEvent>> *>(VT_EVENTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_EVENTS) &&
           verifier.VerifyVector(Events()) &&
           verifier.VerifyVectorOfTables(Events()) &&
           verifier.EndTable();
  }
};

struct RankingEventBatchBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_Events(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<RankingEvent>>> Events) {
    fbb_.AddOffset(RankingEventBatch::VT_EVENTS, Events);
  }
  explicit RankingEventBatchBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RankingEventBatchBuilder &operator=(const RankingEventBatchBuilder &);
  flatbuffers::Offset<RankingEventBatch> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<RankingEventBatch>(end);
    return o;
  }
};

inline flatbuffers::Offset<RankingEventBatch> CreateRankingEventBatch(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<RankingEvent>>> Events = 0) {
  RankingEventBatchBuilder builder_(_fbb);
  builder_.add_Events(Events);
  return builder_.Finish();
}

inline flatbuffers::Offset<RankingEventBatch> CreateRankingEventBatchDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<RankingEvent>> *Events = nullptr) {
  return VW::Events::CreateRankingEventBatch(
      _fbb,
      Events ? _fbb.CreateVector<flatbuffers::Offset<RankingEvent>>(*Events) : 0);
}

}  // namespace Events
}  // namespace VW

#endif  // FLATBUFFERS_GENERATED_RANKINGEVENT_VW_EVENTS_H_
