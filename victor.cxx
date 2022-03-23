#include <stdio.h>
#include <iostream>

#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1D.h>
#include <TPad.h>
#include <TString.h>
#include <gmp.h>
#include <mpfr.h>

int main(int argc, char *argv[]) {
    unsigned int i;
    mpfr_t s, t, u;

    mpfr_init2(t, 200);
    mpfr_set_d(t, 1.0, MPFR_RNDD);
    mpfr_init2(s, 200);
    mpfr_set_d(s, 1.0, MPFR_RNDD);
    mpfr_init2(u, 200);
    for (i = 1; i <= 100; i++) {
	mpfr_mul_ui(t, t, i, MPFR_RNDU);
	mpfr_set_d(u, 1.0, MPFR_RNDD);
	mpfr_div(u, u, t, MPFR_RNDD);
	mpfr_add(s, s, u, MPFR_RNDD);
    }
    printf("Sum is ");
    mpfr_out_str(stdout, 10, 0, s, MPFR_RNDD);
    putchar('\n');
    mpfr_clear(s);
    mpfr_clear(t);
    mpfr_clear(u);
    mpfr_free_cache();

    TApplication theApp("TApp", &argc, argv);
    TH1D *h1 = new TH1D("h1", "titulo", 100, 0, 10);
    TH1D *h2 = new TH1D("h2", "titulo", 100, 0, 10);
    TF1 *f1 = new TF1("f1", "sin(x)/x", 0, 10);
    TF1 *f2 = new TF1("f2", "gaus(0)", 0, 10);
    f2->SetParameter(0, 1);
    f2->SetParameter(1, 5);
    f2->SetParameter(2, 2);

    for (int n = 0; n < 10000; n++) {
	h1->Fill(f1->GetRandom());
	h2->Fill(f2->GetRandom());
    }
    std::cout << h1->GetBinContent(10) << std::endl;

    TCanvas *c = new TCanvas("c", "titulo", 800, 600);
    TPad *p = new TPad("p", "pad", 0.01, 0.02, 0.99, 0.97);
    p->Divide(3, 1);
    p->Draw();

    p->cd(1);
    h1->Draw();
    p->cd(2);
    h2->Draw();
    p->cd(3);
    h1->Draw();
    h2->Draw("same");
    theApp.Run();
    return 0;
}
