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

#ifndef HARDWARE_INTERFACE__IMU_SENSOR_HANDLE_HPP_
#define HARDWARE_INTERFACE__IMU_SENSOR_HANDLE_HPP_

#include <string>

#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/visibility_control.h"

namespace hardware_interface
{
/** A handle used to read the state of a single joint. */
class ImuSensorHandle
{
public:
  struct Data
  {
    std::string name;                                   ///< The name of the sensor
    std::string frame_id;                               ///< The reference frame to which this sensor is associated
    double * orientation = {nullptr};                   ///< A pointer to the storage of the orientation value: a quaternion (x,y,z,w)
    double * orientation_covariance = {nullptr};        ///< A pointer to the storage of the orientation covariance value: a row major 3x3 matrix about (x,y,z)
    double * angular_velocity = {nullptr};              ///< A pointer to the storage of the angular velocity value: a triplet (x,y,z)
    double * angular_velocity_covariance = {nullptr};   ///< A pointer to the storage of the angular velocity covariance value: a row major 3x3 matrix about (x,y,z)
    double * linear_acceleration = {nullptr};           ///< A pointer to the storage of the linear acceleration value: a triplet (x,y,z)
    double * linear_acceleration_covariance = {nullptr}; ///< A pointer to the storage of the linear acceleration covariance value: a row major 3x3 matrix about (x,y,z)
  };

  HARDWARE_INTERFACE_PUBLIC ImuSensorHandle();
  HARDWARE_INTERFACE_PUBLIC ImuSensorHandle(const Data & data);

  HARDWARE_INTERFACE_PUBLIC ImuSensorHandle(
    const std::string & name,                       ///< The name of the sensor
    const std::string & frame_id,                   ///< The reference frame to which this sensor is associated
    const double * orientation,                     ///< A pointer to the storage of the orientation value: a quaternion (x,y,z,w)
    const double * orientation_covariance,          ///< A pointer to the storage of the orientation covariance value: a row major 3x3 matrix about (x,y,z)
    const double * angular_velocity,                ///< A pointer to the storage of the angular velocity value: a triplet (x,y,z)
    const double * angular_velocity_covariance,     ///< A pointer to the storage of the angular velocity covariance value: a row major 3x3 matrix about (x,y,z)
    const double * linear_acceleration,             ///< A pointer to the storage of the linear acceleration value: a triplet (x,y,z)
    const double * linear_acceleration_covariance   ///< A pointer to the storage of the linear acceleration covariance value: a row major 3x3 matrix about (x,y,z)
  );

  HARDWARE_INTERFACE_PUBLIC const std::string & get_name()                           const;
  HARDWARE_INTERFACE_PUBLIC const std::string & get_frame_id()                        const;
  HARDWARE_INTERFACE_PUBLIC const double * get_orientation()                  const;
  HARDWARE_INTERFACE_PUBLIC const double * get_orientation_covariance()        const;
  HARDWARE_INTERFACE_PUBLIC const double * get_angular_velocity()              const;
  HARDWARE_INTERFACE_PUBLIC const double * get_angular_velocity_covariance()    const;
  HARDWARE_INTERFACE_PUBLIC const double * get_linear_acceleration()           const;
  HARDWARE_INTERFACE_PUBLIC const double * get_linear_acceleration_covariance() const;

private:
  std::string name_;
  std::string frame_id_;

  const double* orientation_;
  const double* orientation_covariance_;
  const double* angular_velocity_;
  const double* angular_velocity_covariance_;
  const double* linear_acceleration_;
  const double* linear_acceleration_covariance_;
};

}  // namespace hardware_interface

#endif  // HARDWARE_INTERFACE__IMU_SENSOR_HANDLE_HPP_
