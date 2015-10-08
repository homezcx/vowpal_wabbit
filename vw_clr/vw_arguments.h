/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD (revised)
license as described in the file LICENSE.
*/

#pragma once

#include <msclr\marshal_cppstd.h>
#include "vw.h"
#include <algorithm>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

namespace VW
{
  public ref class VowpalWabbitArguments
  {
  private:
    initonly String^ m_data;
    initonly String^ m_finalRegressor;
    const bool m_testonly;
    const int m_passes;
    List<String^>^ m_regressors;

  internal:
    VowpalWabbitArguments(vw* vw) :
      m_data(gcnew String(vw->data_filename.c_str())),
      m_finalRegressor(gcnew String(vw->final_regressor_name.c_str())),
      m_testonly(!vw->training),
      m_passes((int)vw->numpasses)
    {
      po::variables_map& vm = vw->vm;
      if (vm.count("initial_regressor") || vm.count("i"))
      {
        m_regressors = gcnew List<String^>;

        vector<string> regs = vm["initial_regressor"].as< vector<string> >();
        for (auto iter = regs.begin(); iter != regs.end(); iter++)
          m_regressors->Add(gcnew String(iter->c_str()));
      }
    }

  public:
    property String^ Data
    {
      String^ get()
      {
        return m_data;
      }
    }

    property bool TestOnly
    {
      bool get()
      {
        return m_testonly;
      }
    }

    property int NumPasses
    {
      int get()
      {
        return m_passes;
      }
    }

    property String^ FinalRegressor
    {
      String^ get()
      {
        return m_finalRegressor;
      }
    }

    property List<String^>^ InitialRegressors
    {
      List<String^>^ get()
      {
        return m_regressors;
      }
    }
  };
}
