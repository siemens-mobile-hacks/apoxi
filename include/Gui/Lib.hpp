/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Gui_Lib_hpp)
#define Gui_Lib_hpp

#include <Gui/AbstractEditor.hpp>
#include <Gui/AbstractGrid.hpp>
#include <Gui/AbstractItemGrid.hpp>
#include <Gui/AbstractLineEditor.hpp>
#include <Gui/AbstractMenuList.hpp>
#include <Gui/AbstractMultiLineEditor.hpp>
#include <Gui/Action.hpp>
#include <Gui/Alert.hpp>
#include <Gui/AnimatedTextLine.hpp>
#include <Gui/Bitmap.hpp>
#include <Gui/Brush.hpp>
#include <Gui/CalculatorInputMapper.hpp>
#include <Gui/Caret.hpp>
#include <Gui/CharItem.hpp>
#include <Gui/CheckBox.hpp>
#include <Gui/CheckBoxItem.hpp>
#include <Gui/CheckBoxList.hpp>
#include <Gui/ClientDc.hpp>
#include <Gui/CloseWindowAction.hpp>
#include <Gui/Color.hpp>
#include <Gui/ColorSegmentation.hpp>
#include <Gui/ColorTable.hpp>
#include <Gui/Component.hpp>
#include <Gui/CompoundItem.hpp>
#include <Gui/ContextMenu.hpp>
#include <Gui/Control.hpp>
#include <Gui/ControlDc.hpp>
#include <Gui/ControlFrameView.hpp>
#include <Gui/DateCompoundItem.hpp>
#include <Gui/DateEditor.hpp>
#include <Gui/DateEditorDocument.hpp>
#include <Gui/DateTimeInputMapper.hpp>
#include <Gui/DefaultCaret.hpp>
#include <Gui/DeviceContext.hpp>
#include <Gui/DrawableObject.hpp>
#include <Gui/EditorDocument.hpp>
#include <Gui/AtomItem.hpp>
#include <Gui/EditorLine.hpp>
#include <Gui/Font.hpp>
#include <Gui/FlowLayout.hpp>
#include <Gui/FrameDc.hpp>
#include <Gui/GridLayout.hpp>
#include <Gui/ImageBox.hpp>
#include <Gui/IconSet.hpp>
#include <Gui/IconState.hpp>
#include <Gui/ItemGrid.hpp>
#include <Gui/ItemMenu.hpp>
#include <Gui/ItemTree.hpp>
#include <Gui/InputMapper.hpp>
#include <Gui/LanguageManager.hpp>
#include <Gui/Layouter.hpp>
#include <Gui/LineEditor.hpp>
#include <Gui/Locale.hpp>
#include <Gui/MessageBox.hpp>
#include <Gui/Model.hpp>
#include <Gui/MsgTypes.hpp>
#include <Gui/MultiLineEditor.hpp>
#include <Gui/MultiTapCaret.hpp>
#include <Gui/MultiTapInputMapper.hpp>
#include <Gui/NativeImage.hpp>
#include <Gui/NumericInputMapper.hpp>
#include <Gui/OpenWindowAction.hpp>
#include <Gui/OpenContextMenuAction.hpp>
#include <Gui/PagingMap.hpp>
#include <Gui/PaintDc.hpp>
#include <Gui/PasswordEditor.hpp>
#include <Gui/Pen.hpp>
#include <Gui/PhoneNumberInputMapper.hpp>
#include <Gui/Point.hpp>
#include <Gui/PositionIndicator.hpp>
#include <Gui/PredInputMapper.hpp>
#include <Gui/ProgressBar.hpp>
#include <Gui/ProviderListBox.hpp>
#include <Gui/PushButton.hpp>
#include <Gui/RadioButton.hpp>
#include <Gui/RadioButtonList.hpp>
#include <Gui/RadioButtonItem.hpp>
#include <Gui/Rect.hpp>
#include <Gui/Size.hpp>
#include <Gui/SyncPaintDc.hpp>
#include <Gui/TextBox.hpp>
#include <Gui/TextCompoundItem.hpp>
#include <Gui/TextEditorDocument.hpp>
#include <Gui/TextFormat.hpp>
#include <Gui/TextLine.hpp>
#include <Gui/Theme.hpp>
#include <Gui/ThemeManager.hpp>
#include <Gui/TimeCompoundItem.hpp>
#include <Gui/TimeEditor.hpp>
#include <Gui/TimeEditorDocument.hpp>
#include <Gui/View.hpp>
#include <Gui/Window.hpp>
#include <Gui/WindowFrameView.hpp>
#include <Gui/AbstractToggleAction.hpp>
#include <Gui/ToggleActionGroup.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Gui/CheckBoxAction.hpp>
#include <Gui/BidiManager.hpp>

// Classes which got obsolete with APOXI-version 1.10.0
#ifdef APOXI_COMPAT_1_9_0
    #include <Gui/AbstractListBox.hpp>
    #include <Gui/AbstractMenuAccessor.hpp>
    #include <Gui/ActionExtension.hpp>
    #include <Gui/CancelAction.hpp>
    #include <Gui/ConfirmAction.hpp>
    #include <Gui/DialogWindow.hpp>
    #include <Gui/Menu.hpp>
    #include <Gui/MenuAccessor.hpp>
    #include <Gui/SetLanguageAction.hpp>
    #include <Gui/SetThemeAction.hpp>
    #include <Gui/SoftkeyBar.hpp>
    #include <Gui/TextList.hpp>
    #include <Gui/TextMenuAccessor.hpp>
#endif

// Classes which got obsolete with APOXI-version 1.8.0
#ifdef APOXI_COMPAT_1_7_0
    #include <Gui/MultiTabInputMapper.hpp>
    #include <Gui/Animation.hpp>
#endif

#endif  // Gui_Lib_hpp

