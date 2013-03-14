/*
 * guiLabel.c
 *
 *  Created on: 26.12.2012
 *      Author: Andrey
 */
#include "gui.h"

void labelInit(GUI_LABEL * label, uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	wmObjInit(&label->wmObj, x, y, width, height);
	label->wmObj.Color = LCD_COLOR_GREYL;
	label->wmObj.BorderColor = label->wmObj.Color;
	label->wmObj.BorderWidth = 0;
	label->wmObj.Transparent = 1;
}

//void labelTextInit()

void guiLabelDraw(GUI_LABEL * label)
{
	if (label->wmObj.Visible)
	{
		// Borders
		LCD_SetTextColor(label->wmObj.BorderColor);
		if (label->wmObj.BorderWidth)
		{
			// Top Border
			LCD_DrawFillRect(label->wmObj.xPos, label->wmObj.yPos, label->wmObj.Width, label->wmObj.BorderWidth);
			// Left Border
			LCD_DrawFillRect(label->wmObj.xPos, label->wmObj.yPos, label->wmObj.BorderWidth, label->wmObj.Height);
			// Bottom Border
			LCD_DrawFillRect(label->wmObj.xPos, label->wmObj.yPos+label->wmObj.Height-label->wmObj.BorderWidth, label->wmObj.Width, label->wmObj.BorderWidth);
			// Right Border
			LCD_DrawFillRect(label->wmObj.xPos+label->wmObj.Width-label->wmObj.BorderWidth, label->wmObj.yPos, label->wmObj.BorderWidth, label->wmObj.Height);
		}
		// Back
		if (label->wmObj.Transparent == 0)
		{
			LCD_SetTextColor(label->wmObj.Color);
			LCD_DrawFillRect(label->wmObj.xPos + label->wmObj.BorderWidth,
							label->wmObj.yPos + label->wmObj.BorderWidth,
							label->wmObj.Width - 2*label->wmObj.BorderWidth,
							label->wmObj.Height - 2*label->wmObj.BorderWidth
							);
		}
		// Text
		LCD_SetFont(label->wmTxt.vFont);
		if (label->wmObj.Enable)
			LCD_SetColors(label->wmTxt.TextColor, label->wmObj.Color);
		else
			LCD_SetColors(guiChangeColorLight(label->wmObj.Color, 120), label->wmObj.Color);

		LCD_DrawString(label->wmTxt.Text, label->wmTxt.TextLen, label->wmTxt.TextPosX, label->wmTxt.TextPosY);
	}

}

