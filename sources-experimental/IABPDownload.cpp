/*
 *   Copyright (C) 2005 by Andrea Anzani
 *   oxygenum@tiscali.it      
 *	
*/

//actions for items

#include "IABPDownload.h"
#include "MainWindow.h"
#include "MainController.h"

#define		LOCKWINDOW					if(fView->Lock()){	
#define		UNLOCKWINDOWERROR	{ fView->Unlock(); return B_ERROR; }
#define		UNLOCKWINDOW				fView->Unlock();}


IABPDownloadRemove::IABPDownloadRemove(MainController* controller,MainWindow* view):IActionBP(controller,view){
			 	   		
	 	   		SetIcon(IAction::SIZE_16,LoadIcon("emblem-remove.png"));
	 	   		//SetIcon(IAction::SIZE_48,LoadIcon("emblem-delete.png"));
	 	  		//SetIcon(IAction::SIZE_48_PRESSED,LoadIcon("emblem-delete-down.png"));
	 	  		
	 	  		SetLabel(_T("Remove from this list")); 
}
			 	 
BString 
IABPDownloadRemove::GetDescription(){
 	  return _T("");
}
			 	  

status_t 
IABPDownloadRemove::Perform(BMessage*){

		LOCKWINDOW
		DownloadListItem* row=fView->GetSelectedDownload();
			if(row)
				fController->RemoveDownload(row->fRef);
		UNLOCKWINDOW
		return B_OK;
} 

char 
IABPDownloadRemove::Shortcut(uint32 *modifiers) const {
	return 0;
}

//-------------------------------------------------------------------------------------------------------------------


IABPDownloadStop::IABPDownloadStop(MainController* controller, MainWindow* view):IActionBP(controller,view){
			 	   		
	 	   		SetIcon(IAction::SIZE_16,LoadIcon("stopped-micro.png"));
	 	   		SetIcon(IAction::SIZE_48,LoadIcon("emblem-stop.png"));
	 	  		SetIcon(IAction::SIZE_48_PRESSED,LoadIcon("emblem-stop-down.png"));
	 	  		
	 	  		SetLabel(_T("Stop download")); 
}
			 	 
BString 
IABPDownloadStop::GetDescription(){
 	  return _T("Stop the item download");
}
			 	  

status_t 
IABPDownloadStop::Perform(BMessage*){
		
		LOCKWINDOW
			DownloadListItem* row=fView->GetSelectedDownload();
			if(row)
				fController->StopDownloadItem(row->fRef);
		UNLOCKWINDOW	
		
		return B_OK;
} 

char 
IABPDownloadStop::Shortcut(uint32 *modifiers) const {
	/*if(modifiers)
		*modifiers = B_COMMAND_KEY;
	return 'S';
	*/
	return 0;
}

//-------------------------------------------------------------------------------------------------------------------


IABPDownloadDownload::IABPDownloadDownload(MainController* controller,MainWindow* view):IActionBP(controller,view){
			 	   		
	 	   		SetIcon(IAction::SIZE_16,LoadIcon("download-micro.png"));
	 	   		SetIcon(IAction::SIZE_48,LoadIcon("emblem-download.png"));
	 	  		SetIcon(IAction::SIZE_48_PRESSED,LoadIcon("emblem-download-down.png"));
	 	  		
	 	  		SetLabel(_T("(Re)start download")); 
}
			 	 
BString 
IABPDownloadDownload::GetDescription(){
 	  return _T("Download the selected episode");
}
			 	  

status_t 
IABPDownloadDownload::Perform(BMessage*){
		LOCKWINDOW
			DownloadListItem* row=fView->GetSelectedDownload();
			if(row)
				fController->DownloadItem(row->fRef);
		UNLOCKWINDOW	
		return B_OK;
} 


char 
IABPDownloadDownload::Shortcut(uint32 *modifiers) const {
	/*if(modifiers)
		*modifiers = B_COMMAND_KEY;
	return 'D';*/
	return (char)NULL;
}


//-------------------------------------------------------------------------------------------------------------------


IABPDownloadPlay::IABPDownloadPlay(MainController* controller,MainWindow* view):IActionBP(controller,view){
			 	   		
	 	   		SetIcon(IAction::SIZE_16,LoadIcon("play-micro.png"));
	 	   		SetIcon(IAction::SIZE_48,LoadIcon("emblem-play.png"));
	 	  		SetIcon(IAction::SIZE_48_PRESSED,LoadIcon("emblem-play-down.png"));
	 	  		
	 	  		SetLabel(_T("Play enclosure")); 
}
			 	 
BString 
IABPDownloadPlay::GetDescription(){
 	  return _T("Play the selected episode");
}
			 	  

status_t 
IABPDownloadPlay::Perform(BMessage*){
		LOCKWINDOW
			DownloadListItem* row=fView->GetSelectedDownload();
			if(row)
				fController->PlayItem(row->fRef);
		UNLOCKWINDOW	
		
		return B_OK;
} 

char 
IABPDownloadPlay::Shortcut(uint32 *modifiers) const {
	/*if(modifiers)
		*modifiers = B_COMMAND_KEY;	
	return 'E';
	*/
	
	return (char)NULL;
}


//-------------------------------------------------------------------------------------------------------------------

IABPDownloadFindItem::IABPDownloadFindItem(MainController* controller,MainWindow* view):IActionBP(controller,view){
			 	   		
	 	   		SetIcon(IAction::SIZE_16,LoadIcon("emblem-jump.png"));
	 	   		//SetIcon(IAction::SIZE_48,LoadIcon("www-channel-file.png"));
	 	  		//SetIcon(IAction::SIZE_48_PRESSED,LoadIcon("www-channel-file-down.png"));
	 	  		
	 	  		SetLabel(_T("Find this Item")); 
			 	  
}
			 	 
BString 
IABPDownloadFindItem::GetDescription(){
 	  return _T("");
}
			 	  

status_t 
IABPDownloadFindItem::Perform(BMessage*){
		LOCKWINDOW
		DownloadListItem* row=fView->GetSelectedDownload();
			if(row)
				fController->FindItem(row->fRef);
		UNLOCKWINDOW	
		return B_OK;
}


char 
IABPDownloadFindItem::Shortcut(uint32 *modifiers) const {
	//if(modifiers)
	//	*modifiers = B_COMMAND_KEY;	
	return (char)NULL;
}


