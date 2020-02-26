/**
BSD-3-Clause
Copyright 2019 Alliance for Sustainable Energy, LLC
Redistribution and use in source and binary forms, with or without modification, are permitted provided
that the following conditions are met :
1.	Redistributions of source code must retain the above copyright notice, this list of conditions
and the following disclaimer.
2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions
and the following disclaimer in the documentation and/or other materials provided with the distribution.
3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse
or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER, CONTRIBUTORS, UNITED STATES GOVERNMENT OR UNITED STATES
DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef __EditVariableForm_h
#define __EditVariableForm_h

#include <wx/wx.h>
#include <wx/grid.h>

#include "dllinvoke.h"

class wxNumericCtrl;

class wxExtGridCtrl;

class wxRadioBox;

class EditVariableDialog : public wxDialog {
public:
    EditVariableDialog(wxWindow *parent, const wxString &title);


    void SetVarData(var_data &data) {
        m_var = data;
        UpdateForm();
    }

    void GetVarData(var_data &data) { data = m_var; }

    void UpdateForm();

private:
    wxRadioBox *rbgVarType;
    wxExtGridCtrl *grdArrMat;
    wxButton *btnChooseFile;
    wxTextCtrl *txtValue;
    wxNumericCtrl *numValue;
    wxNumericCtrl *numRows;
    wxNumericCtrl *numCols;

    void OnShortcut(wxCommandEvent &evt);

    void OnTypeChange(wxCommandEvent &evt);

    void OnTextChange(wxCommandEvent &evt);

    void OnNumChange(wxCommandEvent &evt);

    void OnGridCellChange(wxGridEvent &evt);

    void OnRowsColsChange(wxCommandEvent &evt);

    void OnChooseFile(wxCommandEvent &evt);

    var_data m_var;

DECLARE_EVENT_TABLE()
};

#endif

