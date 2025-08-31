#ifndef SHAPEMAKER_H //Yes, putting it in upper case is necessary.
#define SHAPEMAKER_H
class Shapemaker {
private:
  int canvas_width
  int canvas_height
  char drawing_symbol
public:
//Default constructor
Shapemaker() {
  canvas_width = 21;
  canvas_height = 21;
  drawing_symbol = '*';
}
Shapemaker(int cw, int ch, char ds)
{
  canvas_width = cw;
  canvas_height = ch;
  drawing_symbol = ds;
}
int getCanvasWidth()
{return canvas_width;}
int getCanvasHeight()
{return canvas_height;}
char getDrawingSymbol()
{return drawing_symbol;}

void setCanvasWidth(int cw)
{canvas_width = cw;}

void setCanvasHeight(int ch)
{canvas_height = ch;}

void drawing_symbol(int ds)
{drawing_symbol = ds;}

};
#endif
