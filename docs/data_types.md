# Data Types
The data types used with nodes.

 * [Short](#short)
 * [Color](#color)
 * [ImageFormat](#imageformat)
 * [ColorChannel](#colorchannel)
 * [BinaryStream](#binarystream)

## Short
A numeric value from 0-255.

## Color
Represents a color in RGBA format.

The properties of a color are as follows:
 * R - type: Short
   * Represents the `red` portion of a color
 * G - type: Short
   * Represents the `green` portion of a color
 * B - type: Short
   * Represents the `blue` portion of a color
 * A - type: Short
   * Represents the `alpha` portion of a color

## ImageFormat
A list of support image formats.

The currently supported formats are:
 * PNG

## ColorChannel
A color channel of an image. This is typically either `R`, `G`, `B` or `A`.

## BinaryStream
A stream of bytes with a known length. No knowledge of what these bytes represent is known.
