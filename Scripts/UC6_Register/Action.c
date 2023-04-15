Action()
{

	lr_start_transaction("UC6_register");

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
	
	
	lr_start_transaction("click_sign_up_now");
	
		web_reg_find("Text=Please choose a username and password combination for your account",
			LAST);

	
		web_add_auto_header("Sec-Fetch-User",
			"?1");
	
		web_url("login.pl", 
			"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/home.html", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("click_sign_up_now", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("enter_Customer_Profile");
	
	
	web_reg_find("Text=Thank you, <b>{Letter_1}{Letter_2}{Letter_3}{Letter_4}{Letter_5}</b>, for registering and welcome to the Web Tours family.",
			LAST);
	
//		web_reg_find("Text=Please choose a username and password combination for your account",
//			LAST);
	
		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_submit_data("login.pl_2", 
			"Action=http://localhost:1080/cgi-bin/login.pl", 
			"Method=POST", 
			"TargetFrame=info", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=username", "Value={Letter_1}{Letter_2}{Letter_3}{Letter_4}{Letter_5}", ENDITEM, 
			"Name=password", "Value={Letter_5}{Letter_4}{Letter_3}{Letter_2}{Letter_1}", ENDITEM, 
			"Name=passwordConfirm", "Value={Letter_5}{Letter_4}{Letter_3}{Letter_2}{Letter_1}", ENDITEM, 
			"Name=firstName", "Value={Letter_CAPS}{Letter_1}{Letter_2}", ENDITEM, 
			"Name=lastName", "Value={Letter_CAPS}{Letter_2}{Letter_3}", ENDITEM, 
			"Name=address1", "Value={Letter_CAPS}{Letter_3}{Letter_4}", ENDITEM, 
			"Name=address2", "Value={Letter_CAPS}{Letter_4}{Letter_5}", ENDITEM, 
			"Name=register.x", "Value=48", ENDITEM, 
			"Name=register.y", "Value=6", ENDITEM, 
			LAST);

	lr_end_transaction("enter_Customer_Profile", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click_continue");
	
	web_reg_find("Text=Welcome, <b>{Letter_1}{Letter_2}{Letter_3}{Letter_4}{Letter_5}</b>, to the Web Tours reservation pages.",
			LAST);
		
		
		web_url("button_next.gif",
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("click_continue", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("logout");
	
		web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
			LAST);

		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			LAST);
	lr_end_transaction("logout", LR_AUTO);
	
	lr_end_transaction("UC6_register", LR_AUTO);

	return 0;
}