/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "execute/OMTestUtils.h"
#include "test_models/zeroslike/FloatZerosLikeKernel.h"
#include "test_models/zeroslike/NegZerosLikeKernel.h"

namespace onert_micro
{
namespace execute
{
namespace testing
{

using namespace testing;

class ZerosLikeTest : public ::testing::Test
{
  // Do nothing
};

TEST_F(ZerosLikeTest, Float_P)
{
  onert_micro::test_model::TestDataFloatZerosLike test_data_kernel;
  std::vector<float> output_data_vector =
    onert_micro::execute::testing::checkKernel<float>(1, &test_data_kernel);
  EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
}

TEST_F(ZerosLikeTest, Wrong_output_type_NEG)
{
  onert_micro::test_model::NegTestDataInputMismatchZerosLikeKernel test_data_kernel;

  EXPECT_DEATH(checkNEGSISOKernel(&test_data_kernel), "");
}

} // namespace testing
} // namespace execute
} // namespace onert_micro
