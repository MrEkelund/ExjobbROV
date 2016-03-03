#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_sensorfusion_std_msgs_Float32MultiArray and std_msgs::Float32MultiArray

void convert_from_bus(std_msgs::Float32MultiArray* msgPtr, SL_Bus_sensorfusion_std_msgs_Float32MultiArray const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Data_SL_Info.CurrentLength;
    msgPtr->data.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->data[i] =  busPtr->Data[i];
    }
  }
  convert_from_bus(&msgPtr->layout, &busPtr->Layout);
}

void convert_to_bus(SL_Bus_sensorfusion_std_msgs_Float32MultiArray* busPtr, std_msgs::Float32MultiArray const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 10)
    {
      ROS_WARN_NAMED("sensorfusion", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "std_msgs/Float32MultiArray", numItemsToCopy, 10);
      numItemsToCopy = 10;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] =  msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_sensorfusion_std_msgs_Float64MultiArray and std_msgs::Float64MultiArray

void convert_from_bus(std_msgs::Float64MultiArray* msgPtr, SL_Bus_sensorfusion_std_msgs_Float64MultiArray const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Data_SL_Info.CurrentLength;
    msgPtr->data.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->data[i] =  busPtr->Data[i];
    }
  }
  convert_from_bus(&msgPtr->layout, &busPtr->Layout);
}

void convert_to_bus(SL_Bus_sensorfusion_std_msgs_Float64MultiArray* busPtr, std_msgs::Float64MultiArray const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 10)
    {
      ROS_WARN_NAMED("sensorfusion", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "std_msgs/Float64MultiArray", numItemsToCopy, 10);
      numItemsToCopy = 10;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] =  msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_sensorfusion_std_msgs_MultiArrayDimension and std_msgs::MultiArrayDimension

void convert_from_bus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_sensorfusion_std_msgs_MultiArrayDimension const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Label_SL_Info.CurrentLength;
    msgPtr->label.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->label[i] =  busPtr->Label[i];
    }
  }
  msgPtr->size =  busPtr->Size;
  msgPtr->stride =  busPtr->Stride;
}

void convert_to_bus(SL_Bus_sensorfusion_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->label.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("sensorfusion", "Truncating array '%s' in received message '%s' from %d to %d items", "label", "std_msgs/MultiArrayDimension", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->Label_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Label[i] = (uint8_T) msgPtr->label[i];
    }
  }
  busPtr->Size =  msgPtr->size;
  busPtr->Stride =  msgPtr->stride;
}


// Conversions between SL_Bus_sensorfusion_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convert_from_bus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_sensorfusion_std_msgs_MultiArrayLayout const* busPtr)
{
  msgPtr->data_offset =  busPtr->DataOffset;
  {
    const int numItemsToCopy = busPtr->Dim_SL_Info.CurrentLength;
    msgPtr->dim.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_from_bus(&msgPtr->dim[i], &busPtr->Dim[i]);
    }
  }
}

void convert_to_bus(SL_Bus_sensorfusion_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  busPtr->DataOffset =  msgPtr->data_offset;
  {
    int numItemsToCopy = msgPtr->dim.size();
    if (numItemsToCopy > 16)
    {
      ROS_WARN_NAMED("sensorfusion", "Truncating array '%s' in received message '%s' from %d to %d items", "dim", "std_msgs/MultiArrayLayout", numItemsToCopy, 16);
      numItemsToCopy = 16;
    }
    busPtr->Dim_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_to_bus(&busPtr->Dim[i], &msgPtr->dim[i]);
    }
  }
}

