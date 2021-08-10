========================================================================
                            BDE MERGE MODULE
                               README.TXT
========================================================================

-- INTRODUCTION
-- BDE MERGE MODULE FILES
-- USING THE BDE MERGE MODULE
-- INSTALL PATH PROPERTY

____________
INTRODUCTION

The BDE Merge Module supports deployment of BDE-based applications using
the Microsoft Windows Installer service. The BDE Merge Module
contains all of the BDE files, along with registry and configuration
information needed to install those files.

The BDE Merge Module can be used with any setup authoring tool that
supports the Installer service, including InstallShield for Windows
Installer (version 1.10 or higher), Wise for Windows Installer, and the
Microsoft Visual Studio Installer. For more information, see:

http://msdn.microsoft.com/library/psdk/msi/wiport_6gf9.htm

(If this link is broken, go to search.microsoft.com and search for
"Windows Installer Start Page".)


______________________
BDE MERGE MODULE FILES

The BDE Merge Module install package verifies that a compatible version 
of Delphi or C++Builder is already installed.

The Professional Version is compatible with Delphi Professional and
C++Builder Professional. The Enterprise Version is compatible with
Delphi Enterprise, Delphi Client/Server Suite, C++Builder Client/Server
Suite, and C++Builder Enterprise. Compatible Delphi versions are 2, 3,
4, and 5. Compatible C++Builder versions are 1, 3, 4, and 5.

The install package creates a BDE Merge Module directory. By default,
this is C:\Program Files\Borland\BDE Merge Module. This directory
contains the following files.

    * This README.TXT.

    * The Merge Module Wizard: BDEMMCFG.EXE.

    * The Merge Module itself: BDE_PRO.MSM (Professional Version) or
      BDE_ENT.MSM (Enterprise Version).

__________________________
USING THE BDE MERGE MODULE

Follow these steps to incorporate the BDE Merge Module in your project:

    1. Copy BDE_PRO.MSM or BDE_ENT.MSM into the Merge Module directory
       used by your setup authoring tool.

    2. Add a feature called "BDE" to your project.

    3. Specify the BDE Merge Module as a component for the BDE feature.

    4. Build the .MSI file.

    5. Use the BDE Merge Module Wizard (BDEMMCFG.EXE) to define the
       drivers and aliases to be deployed. You can choose BDE aliases,
       or deploy drivers without aliases by choosing them from an option list.
       This information is stored in a BDEMERGE.INI file which must be
       distributed with the .MSI file.

_____________________
INSTALL PATH PROPERTY

The BDE Merge Module obtains the BDE installation directory from the
following property:

   BDE_INSTALL_PATH.E966F0CB_76B3_11D3_945B_00C04FB1760A

The string after the dot is the BDE Merge Module GUID. Use of the GUID
follows the Microsoft Merge Module Naming Convention to ensure a unique
property name.

This property is set by an installer Custom Action, "BDERunning". The
action searches for an existing BDE installation by examining the
registry and the hard drive. If an existing BDE is found, the property
points to its location. Otherwise the property has the default value of
"<PROGRAM FILES>\Common Files\Borland Shared\BDE".

You can change the installation directory with a standard or custom
action. This action should come before the FileCost action in the
InstallExecute sequence, to avoid a disk space error.

========================================================================
Copyright (c) 2001 Borland Software Corporation. 
All rights reserved.
