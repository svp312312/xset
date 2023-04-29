Action()
{

	lr_start_transaction("UC4_View_Itinerary");
		
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
	
		/*Correlation comment - Do not change!  Original value='136171.011259619HAAtcQzpDQVzzzzHtcAcfpHHiDf' Name ='userSession' Type ='ResponseBased'*/
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
				"Snapshot=t2.inf", 
				"Mode=HTML", 
				LAST);
	
	lr_end_transaction("open_home_page", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("enter_login");

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
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=70", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
	lr_end_transaction("enter_login", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click_flights");
	
		web_reg_find("Text=User has returned to the search page",
			LAST);
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
		
	lr_end_transaction("click_flights", LR_AUTO);
	
	lr_think_time(5);
		
	lr_start_transaction("click_itinerary");
	
		web_reg_find("Text/IC=font color\=\"white\"><B>{firstName} {lastName}\n 's Flight Transaction Summary",
		LAST);
	
		web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_itinerary", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("logout");
	
		web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
				LAST);
		
		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_header("Sec-Fetch-User", 
			"?1");
	
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
	
	lr_end_transaction("UC4_View_Itinerary", LR_AUTO);


	return 0;
}