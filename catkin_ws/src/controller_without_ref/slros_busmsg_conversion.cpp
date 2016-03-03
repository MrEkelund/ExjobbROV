#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Controller_without_ref_geometry_msgs_Twist and geometry_msgs::Twist

void convert_from_bus(geometry_msgs::Twist* msgPtr, SL_Bus_Controller_without_ref_geometry_msgs_Twist const* busPtr)
{
  convert_from_bus(&msgPtr->angular, &busPtr->Angular);
  convert_from_bus(&msgPtr->linear, &busPtr->Linear);
}

void convert_to_bus(SL_Bus_Controller_without_ref_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  convert_to_bus(&busPtr->Angular, &msgPtr->angular);
  convert_to_bus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_Controller_without_ref_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Controller_without_ref_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Controller_without_ref_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray and std_msgs::Int64MultiArray

void convert_from_bus(std_msgs::Int64MultiArray* msgPtr, SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Data_SL_Info.CurrentLength;
    msgPtr->data.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->data[i] = (int64_t) busPtr->Data[i];
    }
  }
  convert_from_bus(&msgPtr->layout, &busPtr->Layout);
}

void convert_to_bus(SL_Bus_Controller_without_ref_std_msgs_Int64MultiArray* busPtr, std_msgs::Int64MultiArray const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 10)
    {
      ROS_WARN_NAMED("Controller_without_ref", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "std_msgs/Int64MultiArray", numItemsToCopy, 10);
      numItemsToCopy = 10;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] = (real_T) msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_Controller_without_ref_std_msgs_MultiArrayDimension and std_msgs::MultiArrayDimension

void convert_from_bus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_Controller_without_ref_std_msgs_MultiArrayDimension const* busPtr)
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

void convert_to_bus(SL_Bus_Controller_without_ref_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->label.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Controller_without_ref", "Truncating array '%s' in received message '%s' from %d to %d items", "label", "std_msgs/MultiArrayDimension", numItemsToCopy, 128);
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


// Conversions between SL_Bus_Controller_without_ref_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convert_from_bus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_Controller_without_ref_std_msgs_MultiArrayLayout const* busPtr)
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

void convert_to_bus(SL_Bus_Controller_without_ref_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  busPtr->DataOffset =  msgPtr->data_offset;
  {
    int numItemsToCopy = msgPtr->dim.size();
    if (numItemsToCopy > 16)
    {
      ROS_WARN_NAMED("Controller_without_ref", "Truncating array '%s' in received message '%s' from %d to %d items", "dim", "std_msgs/MultiArrayLayout", numItemsToCopy, 16);
      numItemsToCopy = 16;
    }
    busPtr->Dim_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_to_bus(&busPtr->Dim[i], &msgPtr->dim[i]);
    }
  }
}


// Conversions between SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray and std_msgs::UInt16MultiArray

void convert_from_bus(std_msgs::UInt16MultiArray* msgPtr, SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray const* busPtr)
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

void convert_to_bus(SL_Bus_Controller_without_ref_std_msgs_UInt16MultiArray* busPtr, std_msgs::UInt16MultiArray const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 6)
    {
      ROS_WARN_NAMED("Controller_without_ref", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "std_msgs/UInt16MultiArray", numItemsToCopy, 6);
      numItemsToCopy = 6;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] =  msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Layout, &msgPtr->layout);
}

