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

generatePdf::generatePdf(User *user, userCar *car)
{

    HPDF_Doc pdf;
    HPDF_Font font;
    HPDF_Page page;
    HPDF_REAL tw;
    const static char* text= "";

    pdf = HPDF_New(error_handler,NULL);
    if (!pdf) {
           printf ("error: cannot create PdfDoc object\n");
    }
    if (setjmp(env)) {
        HPDF_Free (pdf);
    }

    //set font
    font = HPDF_GetFont (pdf, "Helvetica", NULL);

    //setting page
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    //writing to pdf
    HPDF_Page_BeginText (page);
    HPDF_Page_SetFontAndSize (page, font, 20);
    text = user->firstName.toStdString().c_str();
    tw = HPDF_Page_TextWidth (page, text);
    HPDF_Page_MoveTextPos (page, 30, (HPDF_Page_GetHeight (page)) -30);
    HPDF_Page_ShowText(page, text);
    HPDF_Page_EndText (page);


   //saving to file
    HPDF_SaveToFile (pdf, "hello.pdf");

    //cleaning
    HPDF_Free (pdf);

}



