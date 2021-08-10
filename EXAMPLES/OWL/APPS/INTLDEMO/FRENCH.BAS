//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   french.bas
//----------------------------------------------------------------------------

Fonction IntlDemo()
    AffecteRéf MonObjet = CréerObjet("Locale.Application")
    AffecteRéf MaFenêtre = MonObjet.Fenêtre
    MaFenêtre.CLocale
    MaFenêtre.LocaleAméricaine
    MaFenêtre.LocaleAnglaise
    MaFenêtre.LocaleFrançaise
    MaFenêtre.LocaleAllemande
    MaFenêtre.LangueAnglaise
    MaFenêtre.LangueFrançaise
    MaFenêtre.LangueAllemande
    AffecteRéf FenêtreEnfante = MaFenêtre.Fenêtre
    FenêtreEnfante.IsAlnum
    FenêtreEnfante.IsAlpha
    FenêtreEnfante.IsAscii
    FenêtreEnfante.IsCntrl
    FenêtreEnfante.IsDigit
    FenêtreEnfante.IsGraph
    FenêtreEnfante.IsLower
    FenêtreEnfante.IsPrint
    FenêtreEnfante.IsPunct
    FenêtreEnfante.IsSpace
    FenêtreEnfante.IsUpper
    FenêtreEnfante.IsXDigit
    MonObjet.Quitter
Fin Fonction
