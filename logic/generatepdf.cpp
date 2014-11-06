#include "generatepdf.h"



jmp_buf env;

#ifdef HPDF_DLL
void  __stdcall
#else
void
#endif
error_handler (HPDF_STATUS   error_no,
               HPDF_STATUS   detail_no,
               void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}

void draw_line  (HPDF_Page page,float x,float y,float z = 0)
{
    HPDF_Page_MoveTo (page, x, y);
    HPDF_Page_LineTo (page, HPDF_Page_GetWidth(page) -z, y);
    HPDF_Page_Stroke (page);
}

void add_text (HPDF_Page page, int position, const char *text, float x = 0, float y = 0)
{
    HPDF_REAL tw;
    int margin = 30;
    int pageHeight = HPDF_Page_GetHeight(page);
    int pageCenter = HPDF_Page_GetWidth(page)/2;
    HPDF_Page_BeginText (page);
    switch (position){
    case 0:
        HPDF_Page_MoveTextPos (page, margin + x , pageHeight - (margin + y));
        break;
    case 1:
        tw = HPDF_Page_TextWidth (page, text);
        HPDF_Page_MoveTextPos (page, pageCenter -tw/2 + x , pageHeight - (margin + y));
        break;
    case 2:
        HPDF_Page_MoveTextPos (page, pageCenter + margin + x , pageHeight - (margin + y));
        break;
    default:
        HPDF_Page_MoveTextPos (page, 0 ,pageHeight);
        break;
    }
    HPDF_Page_ShowText(page, text);
    HPDF_Page_EndText (page);
}

void add_text2 (HPDF_Doc pdf,HPDF_Page page, int position, const char *text,const char *text2, float x = 0, float y = 0, int z = 0)
{
    HPDF_Font font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Font font2 = HPDF_GetFont (pdf, "Courier", NULL);
    HPDF_REAL tw = HPDF_Page_TextWidth (page, text);
    int margin = 30;
    int pageHeight = HPDF_Page_GetHeight(page);
    int pageCenter = HPDF_Page_GetWidth(page)/2;
    HPDF_Page_BeginText (page);
    switch (position){
    case 0:
        HPDF_Page_MoveTextPos (page, margin + x , pageHeight - (margin + y));
        break;
    case 1:
        HPDF_Page_MoveTextPos (page, pageCenter -tw/2 + x , pageHeight - (margin + y));
        break;
    case 2:
        HPDF_Page_MoveTextPos (page, pageCenter + margin + x , pageHeight - (margin + y));
        break;
    default:
        HPDF_Page_MoveTextPos (page, 0 ,pageHeight);
        break;
    }
    HPDF_Page_SetFontAndSize (page, font, 12);
    HPDF_Page_ShowText(page, text);
    HPDF_Page_SetFontAndSize(page,font2,13);
    HPDF_Page_MoveTextPos (page, tw+4-z ,0);
    HPDF_Page_ShowText(page, text2);
    HPDF_Page_EndText (page);
}

generatePdf::generatePdf(User *user, userCar *car)
{
    HPDF_Doc pdf;
    HPDF_Font font;
    HPDF_Page page;
    HPDF_REAL tw;
    const int margin = 30;
    const static char* text= "";
    const HPDF_UINT16 DASH_MODE[] = {3};
    int pageLeftMargin = margin;
    int pageWidth, pageHeight;
    int pageRightMargin, pageMiddle;

    pdf = HPDF_New(error_handler,NULL);
    if (!pdf) {
           printf ("error: cannot create PdfDoc object\n");
    }
    if (setjmp(env)) {
        HPDF_Free (pdf);
    }

    //setting page
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
    //setting margins
    pageWidth = HPDF_Page_GetWidth(page);
    pageHeight = HPDF_Page_GetHeight(page);
    pageLeftMargin = pageWidth -margin;
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize (page, font, 14);
    //first section id and vin
    add_text(page,1,QString::number(car->id).toStdString().c_str());
    add_text(page,1,car->VIN.toStdString().c_str(),0,30);
    //ending section with line
    HPDF_Page_SetLineWidth (page, 1.0);
    HPDF_Page_SetDash (page, DASH_MODE, 1, 1);
    draw_line (page, 0, pageHeight - (margin + 45));
    //user section
    add_text2(pdf,page,0,"First Name:",user->firstName.toStdString().c_str(),0,75);
    add_text2(pdf,page,2,"Last Name:",user->lastName.toStdString().c_str(),0,75);
    add_text2(pdf,page,0,"Primary Contact:",user->phone.toStdString().c_str(),0,95,25);
    add_text2(pdf,page,2,"Email:",user->otherContact.toStdString().c_str(),0,95);
    add_text2(pdf,page,0,"Notes:",user->notes.toStdString().c_str(),0,115);
    HPDF_Page_SetDash (page, NULL, 0, 0);
    HPDF_Page_SetLineWidth (page, 0);
    draw_line (page, margin, pageHeight - (margin + 130), margin);
    //car section
    add_text2(pdf,page,0,"Brand:",car->brand.toStdString().c_str(),0,150);
    add_text2(pdf,page,2,"Plate Number:",car->plateNumber.toStdString().c_str(),0,150);
    add_text2(pdf,page,0,"Color:",car->color.toStdString().c_str(),0,170);
    add_text2(pdf,page,2,"Body Model:",car->model.toStdString().c_str(),0,170);
    add_text2(pdf,page,0,"Motor:",car->motor.toStdString().c_str(),0,190);
    add_text2(pdf,page,2,"Year:",QString::number(car->year).toStdString().c_str(),0,190);
    HPDF_Page_SetLineWidth (page, 1.0);
    HPDF_Page_SetDash (page, DASH_MODE, 1, 1);
    draw_line (page, 0, pageHeight - (margin + 210));
    //hand written section
    add_text2(pdf,page,2,"Identifier:",QString::number(car->id).toStdString().c_str(),100,225,35);
    HPDF_Page_SetFontAndSize (page, font, 14);
    add_text(page,1,"Requested",0,240);
    add_text(page,1,"Worked",0, 470);
    HPDF_Page_SetLineWidth (page, 1.0);
    HPDF_Page_SetDash (page, DASH_MODE, 1, 1);
    draw_line (page, 0, pageHeight - (margin + 750));
    //disclaimer and signature
    HPDF_Page_SetFontAndSize (page, font, 10);
    add_text(page,0,"I,                                  by signing this paper admit and acknowledge that all vechicule tires were well tightened.", 0,775);
    add_text(page,0,"Date:",0,790);
    add_text(page,2,"Signature:",0,790);
    //saving to file
    HPDF_SaveToFile (pdf, "test.pdf");

    //cleaning
    HPDF_Free (pdf);

}
