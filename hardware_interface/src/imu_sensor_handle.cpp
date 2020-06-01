// Copyright 2017 Open Source Robotics Foundation, Inc.
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

#include "hardware_interface/imu_sensor_handle.hpp"

#include <stdexcept>
#include <string>

#include "hardware_interface/macros.hpp"

namespace hardware_interface
{

ImuSensorHandle::ImuSensorHandle()
: name_(),
  frame_id_(),
  orientation_(nullptr),
  orientation_covariance_(nullptr),
  angular_velocity_(nullptr),
  angular_velocity_covariance_(nullptr),
  linear_acceleration_(nullptr),
  linear_acceleration_covariance_(nullptr)
{
}

ImuSensorHandle::ImuSensorHandle(const Data & data)
: name_(data.name),
  frame_id_(data.frame_id),
  orientation_(data.orientation),
  orientation_covariance_(data.orientation_covariance),
  angular_velocity_(data.angular_velocity),
  angular_velocity_covariance_(data.angular_velocity_covariance),
  linear_acceleration_(data.linear_acceleration),
  linear_acceleration_covariance_(data.linear_acceleration_covariance)
{
  THROW_ON_NULLPTR(orientation_)
  THROW_ON_NULLPTR(orientation_covariance_)
  THROW_ON_NULLPTR(angular_velocity_)
  THROW_ON_NULLPTR(angular_velocity_covariance_)
  THROW_ON_NULLPTR(linear_acceleration_)
  THROW_ON_NULLPTR(linear_acceleration_covariance_)
}

ImuSensorHandle::ImuSensorHandle(
  const std::string & name,
  const std::string & frame_id,
  const double * orientation,
  const double * orientation_covariance,
  const double * angular_velocity,
  const double * angular_velocity_covariance,
  const double * linear_acceleration,
  const double * linear_acceleration_covariance
)
: name_(name),
  frame_id_(frame_id),
  orientation_(orientation),
  orientation_covariance_(orientation_covariance),
  angular_velocity_(angular_velocity),
  angular_velocity_covariance_(angular_velocity_covariance),
  linear_acceleration_(linear_acceleration),
  linear_acceleration_covariance_(linear_acceleration_covariance)
{
  THROW_ON_NULLPTR(orientation_)
  THROW_ON_NULLPTR(orientation_covariance_)
  THROW_ON_NULLPTR(angular_velocity_)
  THROW_ON_NULLPTR(angular_velocity_covariance_)
  THROW_ON_NULLPTR(linear_acceleration_)
  THROW_ON_NULLPTR(linear_acceleration_covariance_)
}

const std::string & ImuSensorHandle::get_name()                           const
{
  return name_;
}

const std::string & ImuSensorHandle::get_frame_id()                        const
{
  return frame_id_;
}
const double * ImuSensorHandle::get_orientation()                  const
{
  THROW_ON_NULLPTR(orientation_)
  return orientation_;
}

const double * ImuSensorHandle::get_orientation_covariance()        const
{
  THROW_ON_NULLPTR(orientation_covariance_)
  return orientation_covariance_;
}

const double * ImuSensorHandle::get_angular_velocity()              const
{
  THROW_ON_NULLPTR(angular_velocity_)
  return angular_velocity_;
}

const double * ImuSensorHandle::get_angular_velocity_covariance()    const
{
  THROW_ON_NULLPTR(angular_velocity_covariance_)
  return angular_velocity_covariance_;
}

const double * ImuSensorHandle::get_linear_acceleration()           const
{
  THROW_ON_NULLPTR(linear_acceleration_)
  return linear_acceleration_;
}

const double * ImuSensorHandle::get_linear_acceleration_covariance() const
{
  THROW_ON_NULLPTR(linear_acceleration_covariance_)
  return linear_acceleration_covariance_;
}

}  // namespace hardware_interface
