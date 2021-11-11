const uint8_t sevenSegment_Bitmaps[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0x20, 0x54, 0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x80, 0x02, 
  0x08, 0x00, 0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x80, 0x02, 0x08, 0x00, 
  0x20, 0x80, 0x02, 0x08, 0x54, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 
  0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 
  0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x54, 0x00, 0x80, 
  0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x85, 0x42, 0x00, 
  0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0x20, 0x00, 0x02, 0x00, 0x54, 0x00, 
  0x54, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 
  0x85, 0x40, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 
  0x08, 0x54, 0x00, 0x00, 0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x80, 0x02, 
  0x08, 0x00, 0x20, 0x85, 0x40, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 
  0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x54, 0x20, 0x00, 0x02, 0x00, 0x00, 
  0x20, 0x00, 0x02, 0x00, 0x00, 0x20, 0x05, 0x40, 0x08, 0x00, 0x00, 0x80, 
  0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x54, 0x00, 0x54, 0x20, 0x00, 
  0x02, 0x00, 0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0x20, 0x05, 0x42, 0x08, 
  0x00, 0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x80, 0x02, 0x08, 0x54, 0x00, 
  0x54, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 
  0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 
  0x08, 0x00, 0x00, 0x54, 0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x80, 0x02, 
  0x08, 0x00, 0x20, 0x85, 0x42, 0x08, 0x00, 0x20, 0x80, 0x02, 0x08, 0x00, 
  0x20, 0x80, 0x02, 0x08, 0x54, 0x00, 0x54, 0x20, 0x80, 0x02, 0x08, 0x00, 
  0x20, 0x80, 0x02, 0x08, 0x00, 0x20, 0x85, 0x40, 0x08, 0x00, 0x00, 0x80, 
  0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00
};

const GFXglyph sevenSegment_Glyphs[] PROGMEM = {
  {     0,   1,   1,  10,    0,  -15 },   // 0x20 ' '
  {     0,   0,   0,   0,    0,    0 },   // 0x21 '!'
  {     0,   0,   0,   0,    0,    0 },   // 0x22 '"'
  {     0,   0,   0,   0,    0,    0 },   // 0x23 '#'
  {     0,   0,   0,   0,    0,    0 },   // 0x24 '$'
  {     0,   0,   0,   0,    0,    0 },   // 0x25 '%'
  {     0,   0,   0,   0,    0,    0 },   // 0x26 '&'
  {     0,   0,   0,   0,    0,    0 },   // 0x27 '''
  {     0,   0,   0,   0,    0,    0 },   // 0x28 '('
  {     0,   0,   0,   0,    0,    0 },   // 0x29 ')'
  {     0,   0,   0,   0,    0,    0 },   // 0x2A '*'
  {     0,   0,   0,   0,    0,    0 },   // 0x2B '+'
  {     0,   0,   0,   0,    0,    0 },   // 0x2C ','
  {     1,  10,  21,  10,    2,  -15 },   // 0x2D '-'
  {    28,   4,  21,   0,   -2,  -15 },   // 0x2E '.'
  {     0,   0,   0,   0,    0,    0 },   // 0x2F '/'
  {    39,  10,  21,  10,    2,  -15 },   // 0x30 '0'
  {    66,  10,  21,   9,    1,  -15 },   // 0x31 '1'
  {    93,  10,  21,  10,    2,  -15 },   // 0x32 '2'
  {   120,  10,  21,  10,    2,  -15 },   // 0x33 '3'
  {   147,  10,  21,  10,    2,  -15 },   // 0x34 '4'
  {   174,  10,  21,  10,    2,  -15 },   // 0x35 '5'
  {   201,  10,  21,  10,    2,  -15 },   // 0x36 '6'
  {   228,  10,  21,  10,    2,  -15 },   // 0x37 '7'
  {   255,  10,  21,  10,    2,  -15 },   // 0x38 '8'
  {   282,  10,  21,  10,    2,  -15 }    // 0x39 '9'
};

const GFXfont sevenSegment PROGMEM = {(uint8_t *) sevenSegment_Bitmaps, (GFXglyph *)sevenSegment_Glyphs, 0x20, 0x39, 22};