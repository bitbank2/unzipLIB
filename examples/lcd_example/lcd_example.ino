//
// ZIP library example sketch
//
#include <unzipLIB.h>
#include <bb_spi_lcd.h>
static uint8_t ucTXBuf[1024];
#define TFT_CS 10
#define TFT_RST -1
#define TFT_DC 9
#define TFT_CLK 13
#define TFT_MOSI 11

// Use a zip file in memory for this test
#include "bmp_icons.h"
UNZIP zip; // Statically allocate the 41K UNZIP class/structure
SPILCD lcd;

void setup() {
  Serial.begin(115200);
  while (!Serial) {};
  spilcdSetTXBuffer(ucTXBuf, sizeof(ucTXBuf));
  spilcdInit(&lcd, LCD_ILI9341, FLAGS_NONE, 40000000, TFT_CS, TFT_DC, TFT_RST, -1, -1, TFT_MOSI, TFT_CLK);
  spilcdSetOrientation(&lcd, LCD_ORIENTATION_270);
}

void loop() {
  int rc, x, y;
  char szComment[256], szName[256];
  unz_file_info fi;
  uint8_t ucBitmap[2560]; // temp storage for each icon bitmap 

  spilcdFill(&lcd, 0, DRAW_TO_LCD);
  spilcdWriteString(&lcd, 0, 0, (char *)"Unzip Test", 0xffff, 0, FONT_12x16, DRAW_TO_LCD);
  x = 0; y = 32; // starting point to draw bitmaps
  rc = zip.openZIP((uint8_t *)bmp_icons, sizeof(bmp_icons));
  if (rc == UNZ_OK) {
//     rc = zip.getGlobalComment(szComment, sizeof(szComment));
//     Serial.print("Global comment: ");
//     Serial.println(szComment);
//     Serial.println("Files in this archive:");
     zip.gotoFirstFile();
     rc = UNZ_OK;
     while (rc == UNZ_OK) { // Display all files contained in the archive
        rc = zip.getFileInfo(&fi, szName, sizeof(szName), NULL, 0, szComment, sizeof(szComment));
        if (rc == UNZ_OK) {
            zip.openCurrentFile();
            spilcdWriteString(&lcd, 0, 224, "                           ", 0xff1f, 0, FONT_12x16, DRAW_TO_LCD);
            spilcdWriteString(&lcd, 0, 224, szName, 0xff1f, 0, FONT_12x16, DRAW_TO_LCD);
            rc = zip.readCurrentFile(ucBitmap, 2102); // we know the uncompressed size of these BMP images
            if (rc != 2102) {
                Serial.print("Read error, rc=");
                Serial.println(rc, DEC);
            }
            spilcdDrawBMP(&lcd, ucBitmap, x, y, 1, -1, DRAW_TO_LCD);
            x += 64;
            if (x >= 256) {
              x = 0;
              y += 64;
            }
            delay(1000);
        }
        rc = zip.gotoNextFile();
     }
     zip.closeZIP();
  }
//  while (1) {};
}
