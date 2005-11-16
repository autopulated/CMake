/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmConfigureFileCommand_h
#define cmConfigureFileCommand_h

#include "cmCommand.h"

class cmConfigureFileCommand : public cmCommand
{
public:
  cmTypeMacro(cmConfigureFileCommand, cmCommand);

  virtual cmCommand* Clone() 
    {
      return new cmConfigureFileCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the input file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "CONFIGURE_FILE";}

  /**
   * This determines if the command is invoked when in script mode.
   */
  virtual bool IsScriptable() { return true; }

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Copy a file to another location and modify its contents.";
    }
  
  /**
   * Longer documentation.
   */
  virtual const char* GetFullDocumentation()
    {
      return
        "  CONFIGURE_FILE(InputFile OutputFile\n"
        "                 [COPYONLY] [ESCAPE_QUOTES] [@ONLY])\n"
        "The Input and Ouput files have to have full paths.  "
        "This command replaces any variables in the input file referenced as "
        "${VAR} or @VAR@ with their values as determined by CMake.  If a "
        "variable is not defined, it will be replaced with nothing.  "
        "If COPYONLY is specified, then no variable expansion will take "
        "place.  If ESCAPE_QUOTES is specified then any substituted quotes "
        "will be C-style escaped.  "
        "The file will be configured with the current values of CMake "
        "variables. If @ONLY is specified, only variables "
        "of the form @VAR@ will be replaces and ${VAR} will be ignored.  "
        "This is useful for configuring scripts that use ${VAR}. "
        "Any occurrences of #cmakedefine VAR will be replaced with "
        "either #define VAR or /* #undef VAR */ depending on "
        "the setting of VAR in CMake";
    }

  virtual void FinalPass();
private:
  int ConfigureFile();
  
  std::string m_InputFile;
  std::string m_OuputFile;
  bool m_CopyOnly;
  bool m_EscapeQuotes;
  bool m_Immediate;
  bool m_AtOnly;
};



#endif
