#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include "http_server/stdafx.h"
#include "logger/eventhub_client.h"
#include "http_server/http_server.h"
#include <boost/test/unit_test.hpp>
#include "err_constants.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


using namespace reinforcement_learning;

//send bytes
BOOST_AUTO_TEST_CASE(send_bytes)
{
  //start a http server that will receive events sent from the eventhub_client
  http_helper http_server;
  BOOST_CHECK(http_server.on_initialize(U("http://localhost:8080")));

  //create a client
  eventhub_client eh("localhost:8080", "", "", "", 1, nullptr, nullptr, true);
  
  api_status ret;
  
  std::string message1Str("message 1");
  std::vector<unsigned char> message1(message1Str.begin(), message1Str.end());

  std::string message2Str("message 2");
  std::vector<unsigned char> message2(message2Str.begin(), message2Str.end());

  //send events
  BOOST_CHECK_EQUAL(eh.send(std::move(message1), &ret), error_code::success);
  BOOST_CHECK_EQUAL(eh.send(std::move(message2), &ret), error_code::success);
}