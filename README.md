# CBORING

**NOTE: This is still under development and not ready for use**

The boring cbor library (cboring) is a minimalistic heap free CBOR
implementation that access and store data directly in the user
allocated byte array so no serialization or deserialization is
needed. It has little to no extravagant features, so it is in that
sense boring.

## Motivation

After using libcbor for some time I found that the heap requirements
are very large compared to the size of "on air" bytes, sometimes 10:1
when using large nested maps.  In this use case I rarely access and
modify variables once they have been allocated so by adding values in
place and similarly extract values from the raw byte array valuable
resources can be saved. Still I do not want to be dependent on cmake
or any of the "implement your own callbacks" hassle. Download the
repo, build and link the files and use it.
   
## RFC 8949: CBOR notes

[RFC8949](https://www.rfc-editor.org/rfc/rfc8949.htm)

The underlying data model is an extended version of the JSON data
model
[RFC8259](https://www.rfc-editor.org/rfc/rfc8949.html#RFC8259). In
practice this means that for example maps can have key value pairs of
any type whereas JSON requires keys to be strings.

CBOR encourages being compatible to JSON, that is in my opinion the
sole motivation for using CBOR compared to for example Protobuf.
