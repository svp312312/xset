Action()
{

	lr_start_transaction("UC2_Search_Ticket");
	
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
	
		/*Correlation comment - Do not change!  Original value='136170.188659376HAAtcftpAHQVzzzHtcAcfpfcttHf' Name ='userSession' Type ='ResponseBased'*/
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
				"Snapshot=t4.inf", 
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
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=71", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
		
	lr_end_transaction("enter_login", LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("click_flights");
	
		web_reg_find("Text=User has returned to the search page",
				LAST);

		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			LAST);
		
	
	lr_end_transaction("click_flights", LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("search_tickets");
	
		web_reg_find("Text=Flight departing from <B>{departCity}</B> to <B>{arriveCity}</B> on <B>{departDate}</B>",
					LAST);
	
		web_reg_find("Text=Flight departing from <B>{arriveCity}</B> to <B>{departCity}</B> on <B>{returnDate}</B>",
				LAST);
		
		web_add_header("Origin", 
			"http://localhost:1080");

	
		web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departCity}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arriveCity}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=on", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=54", ENDITEM,
		"Name=findFlights.y", "Value=12", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);
		
	lr_end_transaction("search_tickets", LR_AUTO);
	
//	lr_think_time(5);
//	
//	lr_start_transaction("choose_ticket");
//	
//		web_reg_find("Text=Flight Reservation",
//			LAST);
//	
//		web_submit_data("reservations.pl_2",
//		"Action=http://localhost:1080/cgi-bin/reservations.pl",
//		"Method=POST",
//		"TargetFrame=",
//		"RecContentType=text/html",
//		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
//		"Snapshot=t5.inf",
//		"Mode=HTML",
//		ITEMDATA,
//		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
//		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
//		"Name=advanceDiscount", "Value=0", ENDITEM,
//		"Name=seatType", "Value={seatType}", ENDITEM,
//		"Name=seatPref", "Value={seatPref}", ENDITEM,
//		"Name=reserveFlights.x", "Value=65", ENDITEM,
//		"Name=reserveFlights.y", "Value=6", ENDITEM,
//		LAST);
//	
//	lr_end_transaction("choose_ticket", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("logout");
	
		web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
			LAST);

		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t8.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("logout", LR_AUTO);
	
	lr_end_transaction("UC2_Search_Ticket", LR_AUTO);

	return 0;
}