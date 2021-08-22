# Nodes
This is a list of nodes and their descriptions.

 * [Color](#color)
 * [Serialize](#serialize)

See [here](data_types.md) for a description of the data types used.

## Color
Outputs a static color, regardless of origin.

### Parameters
* Color - type: Color

### Socket Inputs
None.

### Socket Outputs
 * Color

## Serialize
Serializes input color channels into a known image format. Does not serialize to disk, but rather outputs a stream that can be serialized as needed.

### Parameters
 * Format - type: ImageFormat

### Socket Inputs
 * R - type: ColorChannel
 * G - type: ColorChannel
 * B - type: ColorChannel
 * A - type: ColorChannel

### Socket Outputs
 * Stream - type: BinaryStream
