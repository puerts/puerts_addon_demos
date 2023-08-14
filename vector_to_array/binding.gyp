{
  "targets": [
    {
      "target_name": "vector_to_array",
      'include_dirs': [
        "<!@(node -p \"require('puerts').include_dir\")",
      ],
      "defines": [ "BUILDING_PES_EXTENSION", "PES_EXTENSION_WITH_V8_API"],
      "sources": [ "src/vector_to_array.cc", "<!@(node -p \"require('puerts').src_dir\")/pesapi_adpt.c" ]
    }
  ]
} 
