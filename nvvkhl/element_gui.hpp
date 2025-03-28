/*
 * Copyright (c) 2022-2025, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-FileCopyrightText: Copyright (c) 2022-2025, NVIDIA CORPORATION.
 * SPDX-License-Identifier: Apache-2.0
 */

// Various Application utilities
// - Display a menu with File/Quit
// - Display basic information in the window title

#pragma once

#include "imgui.h"
#include "implot.h"

#include "application.hpp"
#include "GLFW/glfw3.h"

// Use:
//  include this file at the end of all other includes,
//  and add engines
//
// Ex:
//   app->addEngine(std::make_shared<AppDefaultMenu>());
//

namespace nvvkhl {


/** @DOC_START
# class nvvkhl::ElementDefaultMenu

>  This class is an element of the application that is responsible for the default menu of the application. It is using the `ImGui` library to create a menu with File/Exit and View/V-Sync.

To use this class, you need to add it to the `nvvkhl::Application` using the `addElement` method.

@DOC_END */

class ElementDefaultMenu : public nvvkhl::IAppElement
{
public:
  void onAttach(nvvkhl::Application* app) override { m_app = app; }

  void onUIMenu() override
  {
    static bool close_app{false};
    bool        v_sync = m_app->isVsync();
#ifdef SHOW_IMGUI_DEMO
    static bool s_showDemo{false};
    static bool s_showDemoPlot{false};
#endif
    if(ImGui::BeginMenu("File"))
    {
      if(ImGui::MenuItem("Exit", "Ctrl+Q"))
      {
        close_app = true;
      }
      ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("View"))
    {
      ImGui::MenuItem("V-Sync", "Ctrl+Shift+V", &v_sync);
      ImGui::EndMenu();
    }
#ifdef SHOW_IMGUI_DEMO
    if(ImGui::BeginMenu("Debug"))
    {
      ImGui::MenuItem("Show ImGui Demo", nullptr, &s_showDemo);
      ImGui::MenuItem("Show ImPlot Demo", nullptr, &s_showDemoPlot);
      ImGui::EndMenu();
    }
#endif  // SHOW_IMGUI_DEMO

    // Shortcuts
    if(ImGui::IsKeyPressed(ImGuiKey_Q) && ImGui::IsKeyDown(ImGuiKey_LeftCtrl))
    {
      close_app = true;
    }

    if(ImGui::IsKeyPressed(ImGuiKey_V) && ImGui::IsKeyDown(ImGuiKey_LeftCtrl) && ImGui::IsKeyDown(ImGuiKey_LeftShift))
    {
      v_sync = !v_sync;
    }

    if(close_app)
    {
      m_app->close();
    }
#ifdef SHOW_IMGUI_DEMO
    if(s_showDemo)
    {
      ImGui::ShowDemoWindow(&s_showDemo);
    }
    if(s_showDemoPlot)
    {
      ImPlot::ShowDemoWindow(&s_showDemoPlot);
    }
#endif  // SHOW_IMGUI_DEMO

    if(m_app->isVsync() != v_sync)
    {
      m_app->setVsync(v_sync);
    }
  }

private:
  nvvkhl::Application* m_app{nullptr};
};

/** @DOC_START
# class nvvkhl::ElementDefaultWindowTitle

>  This class is an element of the application that is responsible for the default window title of the application. It is using the `GLFW` library to set the window title with the application name, the size of the window and the frame rate.

To use this class, you need to add it to the `nvvkhl::Application` using the `addElement` method.

@DOC_END */

class ElementDefaultWindowTitle : public nvvkhl::IAppElement
{
public:
  ElementDefaultWindowTitle(const std::string& prefix = "", const std::string& suffix = "")
      : m_prefix(prefix)
      , m_suffix(suffix)
  {
  }

  void onAttach(nvvkhl::Application* app) override { m_app = app; }

  void onUIRender() override
  {
    // Window Title
    m_dirtyTimer += ImGui::GetIO().DeltaTime;
    if(m_dirtyTimer > 1.0F)  // Refresh every seconds
    {
      const auto& size = m_app->getViewportSize();
      std::string title;
      if(!m_prefix.empty())
      {
        title += fmt::format("{} | ", m_prefix.c_str());
      }
      title += fmt::format("{} | {}x{} | {:.0f} FPS / {:.3f}ms", PROJECT_NAME, size.width, size.height,
                           ImGui::GetIO().Framerate, 1000.F / ImGui::GetIO().Framerate);
      if(!m_suffix.empty())
      {
        title += fmt::format(" | {}", m_suffix.c_str());
      }
      glfwSetWindowTitle(m_app->getWindowHandle(), title.c_str());
      m_dirtyTimer = 0;
    }
  }
  void setPrefix(const std::string& str) { m_prefix = str; }
  void setSuffix(const std::string& str) { m_suffix = str; }

private:
  nvvkhl::Application* m_app{nullptr};
  float                m_dirtyTimer{0.0F};
  std::string          m_prefix;
  std::string          m_suffix;
};

}  // namespace nvvkhl
