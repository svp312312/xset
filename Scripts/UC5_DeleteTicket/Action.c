Action()
{

	char * val_flightID;
	
	lr_start_transaction("UC5_Delete_Ticket");
	
	lr_start_transaction("open_home_page");
	
		web_reg_find("Text=Welcome to the Web Tours site",
				LAST);
	
		web_add_auto_header("Sec-Fetch-Dest",
			"frame");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_add_auto_header("sec-ch-ua", 
			"\"Google Chrome\";v=\"111\", \"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"111\"");
	
		web_add_auto_header("sec-ch-ua-mobile", 
			"?0");
	
		web_add_auto_header("sec-ch-ua-platform", 
			"\"Windows\"");
	
	/*Correlation comment - Do not change!  Original value='136173.538112596HAAttczpDzzzzzzHtcAczpffic' Name ='userSession' Type ='ResponseBased'*/
		web_reg_save_param_attrib(
			"ParamName=userSession",
			"TagName=input",
			"Extract=value",
			"Name=userSession",
			"Type=hidden",
			SEARCH_FILTERS,
			"IgnoreRedirections=No",
			"RequestUrl=*/nav.pl*",
			LAST);
	
		web_url("welcome.pl", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
		
	lr_end_transaction("open_home_page", LR_AUTO);	
		
	lr_think_time(5);
		
	lr_start_transaction("enter_login");
	
		web_reg_find("Text=User password was correct",
			LAST);
		
		web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours",
			LAST);

		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_submit_data("login.pl",
			"Action=http://localhost:1080/cgi-bin/login.pl",
			"Method=POST",
			"TargetFrame=body",
			"RecContentType=text/html",
			"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
			"Snapshot=t2.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=userSession", "Value={userSession}", ENDITEM,
			"Name=username", "Value={login}", ENDITEM,
			"Name=password", "Value={Password}", ENDITEM,
			"Name=login.x", "Value=77", ENDITEM,
			"Name=login.y", "Value=12", ENDITEM,
			"Name=JSFormSubmit", "Value=off", ENDITEM,
			LAST);
	
	lr_end_transaction("enter_login", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("click_itinerary");
	
		web_reg_find("Text/IC=font color\=\"white\"><B>{firstName} {lastName}\n 's Flight Transaction Summary",
		LAST);
	
		web_reg_save_param("flightID",
		"LB/IC=flightID\" value=\"",
		"RB/IC=\"",
		LAST);
	
		web_url("Itinerary Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
		
			
		
	lr_end_transaction("click_itinerary", LR_AUTO);
	
	lr_think_time(5);
		
	lr_start_transaction("delete_ticket");
	

		web_reg_find("Fail=Found",
		"Text/IC={flightID}",
		LAST);

		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_submit_form("itinerary.pl", 
			"Snapshot=t4.inf", 
			ITEMDATA, 
			"Name=1", "Value=on", ENDITEM, 
			"Name=removeFlights.x", "Value=44", ENDITEM, 
			"Name=removeFlights.y", "Value=10", ENDITEM, 
			LAST);
	
//		web_reg_find("Fail=NotFound",
//		"Text/IC={random_flightID}",
//		LAST);
		
//			web_submit_data("itinerary.pl", 
//			"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
//			"Method=POST", 
//			"TargetFrame=", 
//			"RecContentType=text/html", 
//			"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
//			"Snapshot=t4.inf", 
//			"Mode=HTML", 
//			ITEMDATA, 
//			"Name=1", "Value=on", ENDITEM, 
//			"Name=flightID", "Value=123447436-830-JB", ENDITEM, 
//			"Name=flightID", "Value=123453337-1546-JB", ENDITEM, 
//			"Name=flightID", "Value=123453337-2316-JB", ENDITEM, 
//			"Name=flightID", "Value=12344829-3106-jb", ENDITEM, 
//			"Name=flightID", "Value=12344829-3875-jb", ENDITEM, 
//			"Name=flightID", "Value=12347436-4676-jb", ENDITEM, 
//			"Name=flightID", "Value=1234607-53-jb", ENDITEM, 
//			"Name=flightID", "Value=123447047-6176-jb", ENDITEM, 
//			"Name=flightID", "Value=123448162-6952-jb", ENDITEM, 
//			"Name=flightID", "Value=123465955-7754-jb", ENDITEM, 
//			"Name=flightID", "Value=123452232-8482-jb", ENDITEM, 
//			"Name=flightID", "Value=1234744489-92401-JB", ENDITEM, 
//			"Name=flightID", "Value=123468171-10047-JB", ENDITEM, 
//			"Name=flightID", "Value=246928918-10830-JB", ENDITEM, 
//			"Name=flightID", "Value=246947437-11600-JB", ENDITEM, 
//			"Name=flightID", "Value=2469325971-123170-JB", ENDITEM, 
//			"Name=flightID", "Value=246942986-13124-JB", ENDITEM, 
//			"Name=removeFlights.x", "Value=44", ENDITEM, 
//			"Name=removeFlights.y", "Value=10", ENDITEM, 
//			"Name=.cgifields", "Value=11", ENDITEM, 
//			"Name=.cgifields", "Value=7", ENDITEM, 
//			"Name=.cgifields", "Value=17", ENDITEM, 
//			"Name=.cgifields", "Value=2", ENDITEM, 
//			"Name=.cgifields", "Value=1", ENDITEM, 
//			"Name=.cgifields", "Value=16", ENDITEM, 
//			"Name=.cgifields", "Value=13", ENDITEM, 
//			"Name=.cgifields", "Value=6", ENDITEM, 
//			"Name=.cgifields", "Value=3", ENDITEM, 
//			"Name=.cgifields", "Value=9", ENDITEM, 
//			"Name=.cgifields", "Value=12", ENDITEM, 
//			"Name=.cgifields", "Value=14", ENDITEM, 
//			"Name=.cgifields", "Value=15", ENDITEM, 
//			"Name=.cgifields", "Value=8", ENDITEM, 
//			"Name=.cgifields", "Value=4", ENDITEM, 
//			"Name=.cgifields", "Value=10", ENDITEM, 
//			"Name=.cgifields", "Value=5", ENDITEM, 
//		LAST);

		
//		web_url("Itinerary Button", 
//			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
//			"TargetFrame=body", 
//			"Resource=0", 
//			"RecContentType=text/html", 
//			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
//			"Snapshot=t3.inf", 
//			"Mode=HTML", 
//			LAST);
	
	lr_end_transaction("delete_ticket", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("logout");
	
		web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
			LAST);

		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			LAST);
	lr_end_transaction("logout", LR_AUTO);
	
	lr_end_transaction("UC5_Delete_Ticket", LR_AUTO);

	return 0;
}