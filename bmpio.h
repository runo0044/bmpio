#define bitmap_file_header_size 14

struct set {
  unsigned int size;
  unsigned int element_count;
  unsigned int value_size;
  int* key;
  void** value;
};

struct bitmap_file_header {
  char bfType[2];
  int bfSize;
  char bfReserved1[2];
  char bfReserved2[2];
  int bfOffBits;
};

#define bitmap_color_header_size 12

struct bitmap_color_header {
  int bcSize;
  short bcWidth;
  short bcHeight;
  short bcPlanes;
  short bcBitCount;
};

typedef enum biCompression_value {
  BI_RGB = 0,
  BI_RLE8 = 1,
  BI_RLE4 = 2,
  BI_BITFIELDS = 3
}COMPRESSION_TYPE;

#define bitmap_info_header_size 40

struct bitmap_info_header {
  int bcSize;
  int bcWidth;
  int bcHeight;
  short bcPlanes;
  short bcBitCount;
  COMPRESSION_TYPE biCompression;
  int biSizeImage;
  int biXPixPerMeter;
  int biYPixPerMeter;
  int biClrUsed;
  int biCirImportant;
};

union bitmap_data_header {
  struct bitmap_color_header color_header;
  struct bitmap_info_header info_header;
};

typedef enum data_header_type {
  COLOER_HEADER = 12,
  INFO_HEADER = 40,
}DATA_HEADER_TYPE;

struct bitmap_file {
  struct bitmap_file_header file_header;
  DATA_HEADER_TYPE data_header_type;
  union bitmap_data_header data_header;
  struct set coloer_palet;
};
