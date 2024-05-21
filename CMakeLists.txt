#
# Copyright (C) 2023 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#
if(CONFIG_ANDROID_LIBHWBINDER)

  set_property(
    TARGET nuttx
    APPEND
    PROPERTY NUTTX_CXX_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/include)

  if(CONFIG_BINDER_PERFORMANCE_TEST)
    nuttx_add_application(
      MODULE
      ${CONFIG_BINDER_PERFORMANCE_TEST}
      NAME
      aidl_binder
      STACKSIZE
      ${CONFIG_BINDER_PERFORMANCE_STACKSIZE}
      SRCS
      vts/performance/Benchmark_binder.cpp
      COMPILE_FLAGS
      -Wno-shadow)
  endif()

  target_sources(android PRIVATE BpHwBinder.cpp vts/performance/PerfTest.cpp)
  target_compile_options(android PRIVATE -Wno-shadow)

endif()
