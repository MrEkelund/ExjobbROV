\ProvidesClass{rtthesis}[2011/12/05 rtthesis Class v. 0.51]
\NeedsTeXFormat{LaTeX2e}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%  Class history  %%%%%%%%%%%%%%%%%%%%%%%%
% Date        Version  Comment
% --------------------------------------------------------------
% 2011-12-05  0.51     Bugfix release.
%                      Last version tagged by Henrik Tidefelt.
%
% 2011-07-03  0.5      Support for Master's theses based on
%                        Gustaf Hendeby's liuthesis class.
%                      Some changes to thesis setup.
%
% 2010-05-21  0.41     Minor changes.
%
% 2010-03-24  0.4      Bugfixes and better looks.
%                      Some changes to thesis setup.
%
% 2009-12-04  0.3      Supporting compilation theses.
%
% 2009-11-27  0.2      Introducing hyperref support and a lot
%                        more.
%                      Reworked example environment.
%                      Example thesis now contains rtthesis
%                        documentation
%
% 2009-11-17  0.1      Introducing the version history.
%                      Redefined crop marks.
%                      UTF-8 compatibility.
%
% 2005-07-17  0.02a    Version tagged by Gustaf Hendeby
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%
%%%  USER INTERFACE  %%%
%%%%%%%%%%%%%%%%%%%%%%%%

\RequirePackage{keyval}
%%% Title
\define@key{rtthesis}{title}{%
\def\eng@title{#1}%
\let\@title\eng@title%
}
\def\eng@title{\emph{Title in English}}
\let\@title\eng@title
%%% Subtitle
\define@key{rtthesis}{subtitle}{%
\def\eng@subtitle{#1}%
\let\@subtitle\eng@subtitle%
\rteng@subtitletrue%
\let\ifrt@subtitle\ifrteng@subtitle%
}
\def\eng@subtitle{}
\let\@subtitle\eng@subtitle
\newif\ifrteng@subtitle\rteng@subtitlefalse
\let\ifrt@subtitle\ifrteng@subtitle
%%% Title - subtitle separator
\define@key{rtthesis}{subtitlesep}{\gdef\@subtitlesep{#1}}
\def\@subtitlesep{}
%%% Year
\define@key{rtthesis}{year}{\def\thesis@year{#1}}
%%% Month
\define@key{rtthesis}{month}{\def\thesis@month{#1}}
%%% Day of month
\define@key{rtthesis}{day}{\def\thesis@day{#1}}
\def\thesis@day{\@latex@warning@no@line{No day-of-month given}}
%%% Author
\define@key{rtthesis}{author}{\def\@author{#1}}
%%% Thesis type.  Must be one of "phd", "lic", "msc", or left blank.  If present, consistency with the corresponding class option is checked.
\define@key{rtthesis}{type}{\def\thesis@type{#1}}
\def\thesis@type{}
%%% Thesis Number.
\define@key{rtthesis}{thesisNo}{\def\thesisn@{#1}}
%%% ISBN for lic and phd mode
\define@key{rtthesis}{isbn}{\def\@isbn{#1}}
%%% ISRN for msc mode
\define@key{rtthesis}{isrn}{\def\@isrn{#1}}
%%% ISSN number.
\define@key{rtthesis}{issn}{\def\@issn{#1}}
%%% URL for download.
\define@key{rtthesis}{url}{\def\thesis@url{#1}}
\def\thesis@url{}
%%% Master's thesis subject.
\define@key{rtthesis}{subject}{\def\thesis@subject{#1}}
\def\thesis@subject{\emph{Ämnesområde}}
%%% Site where master's thesis work was carried out.
\define@key{rtthesis}{site}{\def\thesis@site{#1}}
\def\thesis@site{\emph{Företag}}
%%% City to appear on title page etc
\define@key{rtthesis}{city}{\def\thesis@city{#1}}
\def\thesis@city{}
%%% Division.
\define@key{rtthesis}{division}{\def\thesis@division{#1}}
\def\thesis@division{\emph{Organisatorisk avdelning}}
%%% Department key.
\define@key{rtthesis}{department}{\def\thesis@department{#1}}
\def\thesis@department{}
%%% Master's thesis examiner.
\define@key{rtthesis}{examiner}{\def\thesis@examiner{#1}}
\def\thesis@examiner{\emph{Examinator}}
%%% Master's thesis supervisor(s).
\define@key{rtthesis}{supervisor}{\def\thesis@supervisor{#1}}
\def\thesis@supervisor{\emph{Handledare}}
%%% Swedish title
\define@key{rtthesis}{swetitle}{%
\def\swe@title{#1}%
\let\@title\swe@title%
}
\def\swe@title{\emph{Svensk titel}}
%%% Swedish subtitle
\define@key{rtthesis}{swesubtitle}{%
\def\swe@subtitle{#1}%
\let\@subtitle\swe@subtitle%
\rtswe@subtitletrue%
\let\ifrt@subtitle\ifrtswe@subtitle%
}
\def\swe@subtitle{}
\newif\ifrtswe@subtitle\rtswe@subtitlefalse
%%% Keywords
\define@key{rtthesis}{keywords}{\def\thesis@keywords{#1}}
\def\thesis@keywords{}
%%% Local ID, e.g., LIU-TEK-LIC-YYYY:N number
\define@key{rtthesis}{localID}{\def\local@ID{#1}}
%%%Publisher.
\define@key{rtthesis}{publisher}{\def\publishername{#1}}
\def\publishername{LiU-Tryck, Linköping, Sweden}
%%% Mail
\define@key{rtthesis}{username}{\gdef\u@name{#1}}
%%% Dedication
\define@key{rtthesis}{dedication}{\gdef\dedic@tion{#1}}
\def\dedic@tion{Intentionally left empty!}
%%% Cover information
\gdef\rtcoverinfo{}

\newcommand*{\rt@selectlanguage@eng}{%
  \renewcommand*\@title{\eng@title}%
  \renewcommand*\@subtitle{\eng@subtitle}%
  \let\ifrt@subtitle\ifrteng@subtitle%
}
\newcommand*{\rt@selectlanguage@swe}{%
  \renewcommand*\@title{\swe@title}%
  \renewcommand*\@subtitle{\swe@subtitle}%
  \let\ifrt@subtitle\ifrtswe@subtitle%
}

\newcommand\setupThesis[1]{%
  \setkeys{rtthesis}{#1}%
  \def\thesistypephd{phd}
  \def\thesistypelic{lic}
  \def\thesistypemsc{msc}
  \def\thesistypebsc{bsc}
  \ifx\thesis@type\@empty
    \ClassError{rtthesis}{%
      The thesis type must be set via setupThesis, by\MessageBreak
      assigning either `phd', `lic', or `msc' to the\MessageBreak
      key <type>%
    }{%
      The thesis type must be set via setupThesis, by\MessageBreak
      assigning either `phd', `lic', or `msc' to the\MessageBreak
      key <type>%
    }%
  \else\ifx\thesis@type\thesistypephd
  \RequirePackage{rtphd}%
  \else\ifx\thesis@type\thesistypelic
  \RequirePackage{rtlic}%
  \else\ifx\thesis@type\thesistypemsc
  \RequirePackage{rtmsc}%
  \else\ifx\thesis@type\thesistypebsc
  \RequirePackage{rtmsc}%
  \else
    \ClassError{rtthesis}{%
      setupThesis was called with an invalid value for\MessageBreak
      the key <type>.  Valid values are `phd', `lic'\MessageBreak
      and `msc'%
    }{%
      setupThesis was called with an invalid value for\MessageBreak
      the key <type>.  Valid values are `phd', `lic'\MessageBreak
      and `msc'%
    }%
  \fi\fi\fi\fi
  \AtBeginDocument{%
    \ifx\thesis@city\@empty
    \def\thesis@city{Linköping}%
    \fi}
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  OPTIONS TO book.cls  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\DeclareOption{10pt}{\PassOptionsToClass{10pt}{book}}
\DeclareOption{11pt}{\PassOptionsToClass{11pt}{book}}
\DeclareOption{12pt}{\PassOptionsToClass{12pt}{book}}

\ExecuteOptions{10pt}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  SELECT CROP BOX AND PAGE LAYOUT  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This must be done before loading crop.sty!

% S5 without intent to use margin paragraphs
\DeclareOption{S5}{
\PassOptionsToPackage{
  twoside, papersize={165mm,240mm}, body={125mm,195mm},% S5
  bindingoffset=5mm, portrait,% The real binding offset is about 1mm, but the pages tend to bend near the back.
  marginparsep=2mm,marginpar=15mm,% 15mm is not very much, except for things as TODO items during writing.
  twocolumn=false, vmarginratio={1:1}, hmarginratio={1:1} % One may consider using the default hmarginratio={2:3}, but this can make the text hard to read near the binding.  A similar effect may obtained by decreasing bindingoffset to, for instance, 1mm or 0mm, but a negative value would be required to get the same effect as hmarginratio={2:3} (body is closer to the binding side of the paper than the other side).
}{geometry}
}

% S5 with intent to use margin paragraphs.
% Note that the S5 paper is not really wide enough to make a layout with reasonably wide margin paragraphs look good.
% This option is provided primarily as a starting point for layouts using margin paragraphs, and separating the S5MP option from the plain S5 option allows the latter to be designed without the limitations imposed by margin paragraphs.
\DeclareOption{S5MP}{
\PassOptionsToPackage{
  twoside, papersize={165mm,240mm}, body={110mm,195mm},% S5
  bindingoffset=1mm, portrait,
  includemp,marginparsep=4mm,marginpar=25mm,% 15mm is not very much, except for things as TODO items during writing.
  twocolumn=false, vmarginratio={1:1}, hmarginratio={3:2}
}{geometry}
}

\DeclareOption{nailing}{
\ExecuteOptions{nobacklist}
\PassOptionsToPackage{
  papersize={155mm,230mm}, body={125mm,200mm},% 10mm smaller than S5 along each dimension.
  bindingoffset=0mm, portrait,
  twocolumn=false, vmarginratio={1:1}, hmarginratio={1:1}
}{geometry}
}


\ExecuteOptions{S5}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  PAPER SIZE AND CROP SETTINGS  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Note that the paper size is typically bigger than the crop box, and that
% crop marks are used to show which part of the printed paper that contains
% the actual page content.
%
% See the geometry options above for page layout.
%
% We don't really bother about bleed boxes here.

\newcommand*{\@info}{\relax}%

\newif\ifrt@loadCrop
\rt@loadCropfalse

\DeclareOption{pdf}{% Do not load crop.sty, and use whatever paper size that was specified via geometry.sty.
% Since crop.sty typically increases the size of the page to that of a paper that is bigger than the crop box,
% the safest way to implement the 'pdf' option is simply to not load crop.sty at all.
  \rt@loadCropfalse
}

\DeclareOption{print}{% Backward compatibility option
  \ClassWarningNoLine{rtthesis}{
    The class option 'print' has been renamed 'pdf'.\MessageBreak
    Since 'pdf' is the default, your problem is solved by\MessageBreak
    simply removing the class option 'print'.}
  \ExecuteOptions{pdf}
}

\DeclareOption{crop}{% To get cropmarks for s5 centered on a4 paper
  \rt@loadCroptrue
  \def\rt@CROPmode{cam}
  \PassOptionsToPackage{ axes, a4, center }{crop}
  \ExecuteOptions{info}
}

\DeclareOption{onA4}{% s5 centered on a4 paper, without crop marks
  \rt@loadCroptrue
  \PassOptionsToPackage{ noaxes, a4, center }{crop}%
  \def\rt@CROPmode{off}
  \ExecuteOptions{noInfo}
}

\DeclareOption{draft}{% s5 centered on a4 DRAFT
  \rt@loadCroptrue
  \PassOptionsToPackage{ a4, center }{crop} % s5 centered on a4 with crops
  \def\rt@CROPmode{off}% Turn off the crop marks.
  \ClassInfo{rtthesis}{This is a DRAFT mode and should hence NOT be
    used for other purposes. Pictures are blank and overfull hboxes
    stand out.}
}

%%% These declarations must come after \DeclareOption{crop} and friends!
\DeclareOption{info}{%
  \renewcommand*{\@info}{{%
    \global\advance\CROP@index\@ne%
    \def\x{\discretionary{}{}{\hbox{\kern.5em---\kern.5em}}}%
    \advance\paperwidth-20\p@%
    \dimen@5mm%
    \ifx\CROP@pagecolor\@empty%
    \else%
      \advance\dimen@\CROP@overlap%
    \fi%
    \hb@xt@\z@{%
      \hss%
      \vbox to\z@{%
        \centering%
        \hsize\paperwidth%
        \vss%
        \normalfont%
        \small%
        \CROP@font{%
          \texttt{\jobname}:~\the\year-\two@digits{\the\month}-\two@digits{\the\day}\:\:%
          \CROP@time\x\the\CROP@index~(``\thepage'')\strut%
        }%
        \vskip\dimen@%
      }%
      \hss%
    }%
  }}%
}

\DeclareOption{noInfo}{\renewcommand*{\@info}{\relax}}


\ExecuteOptions{pdf}


%%%%%%%%%%%%%%%%%%%%%%%%
%%%  INPUT ENCODING  %%%
%%%%%%%%%%%%%%%%%%%%%%%%

%%% Note: It is too dangerous to have a default value for the encoding, so we
%%% must detect if the user fails to select it explicitly.
\newif\ifrt@InputEncUTFUnspecified
\rt@InputEncUTFUnspecifiedtrue
\newif\ifrt@InputEncUTF
\DeclareOption{latin1}{%
\rt@InputEncUTFfalse
\rt@InputEncUTFUnspecifiedfalse
\PassOptionsToPackage{latin1}{rtlic}%
\PassOptionsToPackage{latin1}{rtphd}%
\PassOptionsToPackage{latin1}{rtthesis-captions}%
\PassOptionsToPackage{latin1}{rtthesis-papers-captions}%
}
\DeclareOption{utf8}{%
\rt@InputEncUTFtrue
\rt@InputEncUTFUnspecifiedfalse
\PassOptionsToPackage{utf8}{rtlic}%
\PassOptionsToPackage{utf8}{rtphd}%
\PassOptionsToPackage{utf8}{rtthesis-captions}%
\PassOptionsToPackage{utf8}{rtthesis-papers-captions}%
}


%%%%%%%%%%%%%%%%%%%%%
%%%  THESIS TYPE  %%%
%%%%%%%%%%%%%%%%%%%%%

\DeclareOption{phd}{%
  \ClassError{rtthesis}{%
    The class option `phd' is obsolete.  The thesis type\MessageBreak
    shall be set via the <type> key in the call to\MessageBreak setupThesis instead%
  }{%
    The class option `phd' is obsolete.  The thesis type\MessageBreak
    shall be set via the <type> key in the call to\MessageBreak setupThesis instead%
  }%
}

\DeclareOption{lic}{%
  \ClassError{rtthesis}{%
    The class option `lic' is obsolete.  The thesis type\MessageBreak
    shall be set via the <type> key in the call to\MessageBreak setupThesis instead%
  }{%
    The class option `lic' is obsolete.  The thesis type\MessageBreak
    shall be set via the <type> key in the call to\MessageBreak setupThesis instead%
  }%
}

\DeclareOption{nobacklist}{%
  \PassOptionsToPackage{noliclist}{rtlic}
  \PassOptionsToPackage{nophdlist}{rtphd}
}


%%%%%%%%%%%%%%
%%%  FONT  %%%
%%%%%%%%%%%%%%

%%% The choice of font has more implications than just loading of different font packages.
%%% One thing to notice is that the theorem font will be changed from italics to slanted when
%%% using KpFonts in order to take full advantage of the slanted small caps.

\newif\ifrt@slantsc

\DeclareOption{kp}{\def\rt@textfont{kpfonts}\rt@slantsctrue}
\DeclareOption{times}{\def\rt@textfont{times}\rt@slantscfalse}
\DeclareOption{lm}{\def\rt@textfont{lm}\rt@slantscfalse}

\ExecuteOptions{kp}


%%%%%%%%%%%%%%%%%%%%%
%%%  EXTRA STUFF  %%%
%%%%%%%%%%%%%%%%%%%%%

\newsavebox{\@removeenvinment}

\DeclareOption{noextras}{%
  \ExecuteOptions{notitlepage,noabstract,nopreface,noacknowledgements,nonotation}%
  \OptionNotUsed}
\DeclareOption{notitlepage}{%
  \AtEndOfPackage{\let\maketitle=\relax}}
\DeclareOption{noabstract}{%
  \AtEndOfPackage{\renewenvironment{abstract}[1][english]{%
      \begin{lrbox}{\@removeenvinment}}%
      {\end{lrbox}}}}
\DeclareOption{nopreface}{%
  \AtEndOfPackage{\renewenvironment{preface}{%
      \begin{lrbox}{\@removeenvinment}}%
      {\end{lrbox}}}}
\DeclareOption{noacknowledgements}{%
  \AtEndOfPackage{\renewenvironment{acknowledgments}{%
      \begin{lrbox}{\@removeenvinment}}%
      {\end{lrbox}}}}
\DeclareOption{nonotation}{%
  \AtEndOfPackage{\renewenvironment{notation}{%
      \begin{lrbox}{\@removeenvinment}}%
      {\end{lrbox}}}}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  LOOK OF THEOREM-LIKE ENVIRONMENTS  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Define theorems or not.
\newif\ifrt@deftheorems
\rt@deftheoremstrue
\DeclareOption{notheorems}{\rt@deftheoremsfalse}

% Use same counter for theorem-like environments?
\newif\ifrt@shareTheoremCounter
% Do not use \PassOptionsToPackage to propagate these options to rtthesis-theorems here!
% To make things work the \PassOptionsToPackage code is put just before the \RequirePackage{rtthesis-theorems},
% and uses the final setting of \ifrt@shareTheoremCounter to pass the correct option.
\DeclareOption{sharecounter}{\rt@shareTheoremCountertrue}
\DeclareOption{nosharecounter}{\rt@shareTheoremCounterfalse}

\ExecuteOptions{nosharecounter}

% Put breaks after theorem (and similar) labels?
% The options 'break' and 'nobreak' will be captured by rtthesis-theorems.sty.

% Choice of definition style
% The options 'definition=theorem', 'definition=naked', and 'definition=marks' will be captured by rtthesis-theorems.sty.


%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  HYPERREF SUPPORT  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%

% If hyperref is used, it should be loaded early, and hence it must be loaded by the class.
\newif\ifrt@UseHyperref
\newif\ifrt@UseBackref
\DeclareOption{hyperref}{\rt@UseHyperreftrue
\PassOptionsToPackage{colorlinks=false,pdfborder={0 0 0},bookmarksopen=true,bookmarksopenlevel=1,bookmarksnumbered=true,hyperfootnotes=false,plainpages=false,pdfpagelabels}{hyperref}}
\DeclareOption{nohyperref}{\rt@UseHyperreffalse}

\DeclareOption{backref}{\rt@UseBackreftrue}
\DeclareOption{nobackref}{\rt@UseBackreffalse}

\ExecuteOptions{hyperref}
\ExecuteOptions{backref}


% When making the bookmarks, we need to know whether the user plans to have part divisions.
\newcounter{rt@toplevel}
\setcounter{rt@toplevel}{-1}
\DeclareOption{noparts}{\setcounter{rt@toplevel}{0}}
\DeclareOption{parts}{\setcounter{rt@toplevel}{-1}}

\ExecuteOptions{parts}


%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  PARAGRAPH BERAKS  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%

% Use parskip.sty and adjust sectioning commands?
% Note that the sub-packages rtthesis-theorems and rtthesis-example will
% detect that parskip is loaded, so we don't have to pass any options to these
% packages.
\newif\ifrt@parskip
\DeclareOption{noparskip}{\rt@parskipfalse}
\DeclareOption{parskip}{\rt@parskiptrue}

\ExecuteOptions{noparskip}


%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  NATBIB CONFLICTS  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%

\newif\ifrt@usebibunits
\DeclareOption{usebibunits}{\rt@usebibunitstrue}

\DeclareOption{numbers}{%
\ifrt@usebibunits
\ClassError{rtthesis}{%
  The natbib option `numbers' is in some unidentified\MessageBreak
  conflict with some other package loaded by rtthesis.\MessageBreak
  If you know how to resolve the conflict, use option\MessageBreak
  `forcenumbers' instead, and inform the rtthesis\MessageBreak
  maintainer about your workaround%
}{%
  The natbib option `numbers' is in some unidentified\MessageBreak
  conflict with some other package loaded by rtthesis.\MessageBreak
  If you know how to resolve the conflict, use option\MessageBreak
  `forcenumbers' instead, and inform the rtthesis\MessageBreak
  maintainer about your workaround%
}
\fi
}
\DeclareOption{forcenumbers}{\PassOptionsToPackage{numbers}{natbib}}



% Process options here
\ProcessOptions\relax


\ifrt@InputEncUTFUnspecified
\ClassError{rtthesis}{%
  One of the options `latin1' and `utf8' must be given\MessageBreak
  to select the character encoding of the loaded\MessageBreak
  captions.  Guessing your preference is just too\MessageBreak
  dangerous%
}{%
  One of the options `latin1' and `utf8' must be given\MessageBreak
  to select the character encoding of the loaded\MessageBreak
  captions.  Guessing your preference is just too\MessageBreak
  dangerous%
}
\fi


%%%%%%%%%%%%%%%%%%%%%
%%%  SETUP STUFF  %%%
%%%%%%%%%%%%%%%%%%%%%

\LoadClass{book}
\RequirePackage[ pdftex=false, dvips=false, vtex=false ]{geometry}[2002/07/08]

\ifrt@loadCrop
\RequirePackage{crop}[2001/11/16]
\crop[\rt@CROPmode,font=\mdseries\upshape\scriptsize]
\let\CROP@info\@info
\else
% Since crop.sty always loads color.sty, we compensate for the loss here.
\RequirePackage{color}
\fi
\RequirePackage{graphicx}

% These packages are likely to work better if loaded before hyperref.
\RequirePackage{url}

% Fonts and input definitions
\RequirePackage[T1]{fontenc}
\RequirePackage{\rt@textfont}
\@ifpackageloaded{kpfonts}{}{% In case KpFonts was not loaded:
  \RequirePackage[intlimits]{amsmath}
  \RequirePackage{amsfonts, amssymb}
  \providecommand{\textothersc}[1]{\textsc{#1}}
}
\ifrt@slantsc
\RequirePackage{slantsc}% For access to slanted and italic smallcaps.  Not all fonts support this, but kpfonts do.
\PassOptionsToPackage{slanted}{rtthesis-theorems}
%%% Anyone how knows how to make the slanted small caps can be substituted for italic small caps?
%%% Please help!
%%% The following looks like a nice idea to support small caps in italics, but it doesn't work.
%\AtBeginDocument{\DeclareFontShape{T1}{jkpk}{m}{scit}{ <-> sub * jkpk/m/scsl }{}}
%%% The following attempt to mimic what's inside slantsc also fails.  We get the slanted small caps in place of the italics, but at the price of somehow messing up pretty much everything else quite badly!
% \DeclareFontFamily{T1}{jkpk}{}
% \DeclareFontShape{T1}{jkpk}{m}{scsl}{<5><6><7><8><9><10><10.95><12><14.4><17.28><20.74><24.88><29.86><35.83>genb*ecsc}{}
% \DeclareFontShape{T1}{jkpk}{bx}{scsl}{<5><6><7><8><9><10><10.95><12><14.4><17.28><20.74><24.88><29.86><35.83>genb*ecoc}{}
% \DeclareFontShape{T1}{jkpk}{m}{scit}{<->ssub * jkpk/m/scsl}{}
% \DeclareFontShape{T1}{jkpk}{bx}{scit}{<->ssub * jkpk/bx/scsl}{}
%%% End of failing attempts to get the slanted small caps in place of the italics.
\fi
\RequirePackage{courier}
\RequirePackage[scaled]{helvet}
\RequirePackage[activate]{pdfcprot}% Activate hanging punctuation in pdfTeX.  This _can_ be fine-tuned, but we don't.
\ifrt@parskip
\RequirePackage{parskip}% There is more stuff related to rt@parskip later in this file, but the parskip package itself produces a warning if loaded too late.
\fi
\newlength{\rt@parskip}
\newlength{\rt@parindent}
\setlength{\rt@parskip}{\parskip}
\setlength{\rt@parindent}{\parindent}

%%% We now load packages that must be loaded before hyperref.
%%% It would be possible to load these packages only when hyperref is requested, but this would make the use of the hyperref class option (to be introduced soon) confusing.
%%% Another option would be to introduce a class option for each class that needs to be loaded before hyperref, but that does not scale well, and users will not know about these options and run into all sorts of package loading order issues.
\RequirePackage{float}
\RequirePackage{index}
\ifrt@usebibunits
\RequirePackage{bibunits}% Load before natbib.  We should not pass sectionbib here.  It is better to let some magic work out the correct level.  At the time of writing, I can't see how this works.  But it works.
\fi
\RequirePackage[round]{natbib}% This should be loaded early.  It is much too late to postpone it until a user decision after the class has been loaded.
\RequirePackage{bibentry}% Load after natbib, and before hyperref.
\AtBeginDocument{\relax\nobibliography*}% See the bibentry documentation!
\makeindex
\RequirePackage{xcolor}% So that link border colors may be set.
\RequirePackage{ifthen}
\RequirePackage{calc}

% The package caption.sty is loaded in "incompatibility mode".  It doesn't seem to matter where in this file we load
% the package; the compatibility check will be made much later nevertheless.
\RequirePackage[margin=1em, labelfont=bf,
                singlelinecheck=true, font=sl,
                compatibility=false% Unsupported feature that suppresses the incompatibility checks...
                ]{caption}
\captionsetup[figure]{position=bottom}
\captionsetup[table]{position=top}
\ifrt@parskip
% There is some kind of conflict between captions, subfig, and parskip.  This fix was found in a LaTeX forum on the WWW.
\DeclareCaptionOption{parskip}[]{}
\fi

\newcommand*{\rtthesis@assertnonobackref}{\relax}
\ifrt@UseBackref
%%% === Beginning of hack ===
%%% Here comes a hack provided at http://qianglee.blogspot.com/2006/08/make-bibentry-compatible-with-backref.html .
%%% The purpose is to make bibentry work together with backref (possibly loaded via hyperref).
%%% Before backref messes up, we need to capture the definitions from natbib, so we load bibentry first, then do the hack,
%%% and finally load hyperref.
%%% Note that this fix assumes that natbib has already been loaded!  Who did that?!
\let\BRatbibitem\BR@bibitem
\AtBeginDocument{%
\begingroup
  \makeatletter
  \let\BR@bibitem\BRatbibitem
\endgroup
}
%%% === End of hack ===
%%% In addition to the problems with bibentry, there seems to be problems with bibunits that we currently have no solution to.
\renewcommand*{\rtthesis@assertnonobackref}{%
  \ClassError{rtthesis}{%
    The `backref' class option is incompatible with\MessageBreak
    features of the bibunits package.  If you insist\MessageBreak
    to use bibunits features, you need to turn back\MessageBreak
    references off using the `nobackref' class option%
  }{%
    The `backref' class option is incompatible with\MessageBreak
    features of the bibunits package.  If you insist\MessageBreak
    to use bibunits features, you need to turn back\MessageBreak
    references off using the `nobackref' class option%
  }%
}
\fi

%%% Now, it should be safe to load hyperref.  Note that most packages should be loaded after hyperref, so be very careful when moving stuff across this point in the file!
\ifrt@UseHyperref
\ifrt@UseBackref
\PassOptionsToPackage{backref=page}{hyperref}
\fi
\RequirePackage{hyperref}
\AtEndDocument{
  \ifthenelse{\value{rt@toplevel}=0}{
    %%% In case there are no parts, the part counter should still be at zero.
    \ifthenelse{\value{part}=0}{}{\ClassWarningNoLine{rtthesis}{%
        Class loaded with indication that there would be no\MessageBreak
        part divisions in the document.  However, the part\MessageBreak
        count is non-zero at the end of the document.  Check\MessageBreak
        that the PDF bookmarks are OK
      }}}{
    %%% In case there are parts, the part counter should be non-zero here.
    \ifthenelse{\value{part}=0}{\ClassWarningNoLine{rtthesis}{%
        Class loaded with indication that there would be part\MessageBreak
        divisions in the document.  However, the part count is\MessageBreak
        still zero at the end of the document.  Check that the\MessageBreak
        PDF bookmarks are OK
      }}{}
  }
}
%%% In order to get the PDF bookmarks right, we need to make chapters and sections appear on the part level in the frontmatter and backmatter.
\let\rt@bookfrontmatter\frontmatter
\let\rt@bookmainmatter\mainmatter
\let\rt@bookbackmatter\backmatter
\renewcommand{\frontmatter}{%
\rt@bookfrontmatter
\def\toclevel@chapter{\thert@toplevel}%
\def\toclevel@section{\thert@toplevel}%
}
\renewcommand{\mainmatter}{%
\rt@bookmainmatter
\def\toclevel@chapter{0}
\def\toclevel@section{1}
}
\renewcommand{\backmatter}{%
\rt@bookbackmatter
\def\toclevel@chapter{\thert@toplevel}%
\def\toclevel@section{\thert@toplevel}%
}
% TODO: call \hypersetup AtBeginDocument with info about title, keywords etc.
\else% Not using hyperref.
%%% Provide alternatives to some hyperref commands that one might typically invoke explicitly in case hyperref is present.
\RequirePackage{nohyperref}
%%% The starred forms of \ref, \eqref, and \pageref are missing in nohyperref.sty.  These are provided below.
\RequirePackage{suffix}
\ClassWarningNoLine{rtthesis}{%
  Adding things that are missing in nohyperref.  Some day\MessageBreak
  these things will probably be found in nohyperref, and\MessageBreak
  then these definitions should be removed from here}
\AtEndOfClass{%
\let\ref@NoStar=\ref
\renewcommand{\ref}{\@ifstar\ref@NoStar\ref@NoStar}%
\let\eqref@NoStar=\eqref
\renewcommand{\eqref}{\@ifstar\eqref@NoStar\eqref@NoStar}%
\let\pageref@NoStar=\pageref
\renewcommand{\pageref}{\@ifstar\pageref@NoStar\pageref@NoStar}%
\let\pdfstringdefDisableCommands=\undef  % GH:  Ugly hack which should not be neccessary
}
%%%
\ifrt@UseBackref
\ClassWarningNoLine{rtthesis}{%
  There seems to be compatibility issues between option\MessageBreak
  backref and the bibentry package, when hyperref is not\MessageBreak
  loaded.  That is, if you use the bibentry package and\MessageBreak
  turn hyperref off, it is also recommended that you\MessageBreak
  turn back references off using the nobackref class\MessageBreak
  option}
\RequirePackage[pageref]{backref}
\fi
%\RequirePackage{nameref}% nameref is automatically loaded by hyperref... but seems not to work without hyperref.
\providecommand{\nameref}[1]{%
  \ClassWarning{rtthesis}{%
    The command nameref does not work without hyperref\MessageBreak
    being loaded.  Using plain reference instead,}
  \ref{#1}}
\fi

\newcommand{\pdfbookmarkTopLevel}[2]{%
  \ifthenelse{\value{rt@toplevel}=0}{%
    \pdfbookmark[0]{#1}{#2}%
  }{%
    \pdfbookmark[-1]{#1}{#2}%
  }
}

\providecommand{\backref}{\relax}
\providecommand{\backrefalt}{\relax}
\renewcommand*{\backref}[1]{}
\renewcommand*{\backrefalt}[4]{%
  \ifcase #1 %
    Not cited.%
  \or
    Cited on page #2.%
  \else
    Cited on pages #2.%
  \fi
}

% In case we didn't load the backref package (perhaps via hyperref), it may be good to have the following void definitions around.
\providecommand{\backrefparscanfalse}{}
\providecommand{\backrefparscantrue}{}


\RequirePackage{tocloft}% Get control over table of contents etc.
%%% First ensure that we get the usual section* heading, and add a pdf bookmark while we're at it!
\setlength{\cftbeforetoctitleskip}{0pt}
\setlength{\cftaftertoctitleskip}{0pt}
\renewcommand{\cfttoctitlefont}[1]{%
\ifrt@UseHyperref
\pdfbookmarkTopLevel{\contentsname}{thetocanchor}%
\fi
\@makeschapterhead{#1}%
}
%%% ... then we tune the toc...
\AtBeginDocument{\cftpagenumbersoff{part}}
\cftsetpnumwidth{2em}
\ifrt@parskip
\setlength{\cftparskip}{0.3ex}
\fi

\renewcommand{\cftmarktoc}{\markboth{\contentsname}{\contentsname}}  % Needed to not get CONTENTS (with capital letters) in the header of the Contents, should be loaded after tocloft

\RequirePackage[margin=.5em, font={sl,small}]{subfig} % Must be loaded after tocloft.
% tocbibind shall be loaded after hyperref.  Otherwise, some pdf bookmarks will be missing (like the one for the index).
\RequirePackage[ chapter, nottoc ]{tocbibind} % Fix heading in bibs etc
\renewcommand*\tocetcmark[1]{\markboth{#1}{#1}}


\RequirePackage{sectsty}        %Redefine section captions

\newcommand*{\chapternamefont} [1]
   {\gdef\SS@chapnamefont{\SS@sectid{1}\SS@nopart\SS@makeulinepartchap#1}}

\renewcommand*{\chapterfont}[1]
   {\chapternumberfont{#1}
     \chapternamefont{#1}
     \chaptertitlefont{#1}}

\allsectionsfont{\sffamily}
% Make ragged right for *section headings, for better behavior with
% long titles
\sectionfont{\sffamily\raggedright}
\subsectionfont{\sffamily\raggedright}
\subsubsectionfont{\sffamily\raggedright}

\DeclareRobustCommand\em% New look to emphasis text
  {\@nomath\em \ifdim \fontdimen\@ne\font >\z@
    \upshape \else \slshape \fi}


% Select the input encoding to be used in the document, and from this point in the class file too.
% I need to comment a bit on this...
% It is really strange how the input encoding works before inputenc.sty is loaded.  If we don't load inputenc.sty until
% the end of the class, it seems like the other packages that we load may use latin-1, and the packages will work even
% if we later switch input encoding to utf-8.  However, if we make the selection of latin-1 explicit here by loading
% inputenc.sty with option "latin1" at this point, then the packages encoded in latin-1 will not work if we later switch
% to utf-8.
%
% It is because of this strange behavior that I prefer to make the choice of input encoding explicit here.  Then we know what
% encoding to use in the packages that are loaded by the class.
%
% The strange behavior could be related to how inputenc.sty is currently implemented.  That is, that the actual encoding
% doesn't change until LaTeX encounters a character outside the lower 8-bit range.  Exactly how this would explain things, I
% don't know, but even if I did, this seems like a detail of implementation and not something that this class should rely on.
\ifrt@InputEncUTF
\RequirePackage[utf8]{inputenc}
\RequirePackage{rtthesis-utf8-ext}% Add additional characters.
\else
\RequirePackage[latin1]{inputenc}
\fi

\RequirePackage[swedish, english]{babel}
\AtBeginDocument{\relax\selectlanguage{english}}% Can't see why the \relax is needed here.  However, it really was needed at one point, so be very careful if you plan to remove it!  Hint: to detect problems after removing it, select a language that does not exist, turn off the hyperref option, and play around with other options as well, and make sure that the document always fails to compile due to the bad language name.

\RequirePackage{rtthesis-papers}

\RequirePackage{rtthesis-captions}
\RequirePackage{rtthesis-papers-captions}


%%% Theorem environments %%%
%Only specify theorems if the notheorems option is not specified
\ifrt@shareTheoremCounter
\PassOptionsToPackage{sharecounter}{rtthesis-theorems}%
\else
\PassOptionsToPackage{nosharecounter}{rtthesis-theorems}%
\fi
\ifrt@deftheorems
\RequirePackage{rtthesis-theorems}% Load after parskip!
\fi

\RequirePackage{rtthesis-example}% Load after parskip!


% Page headers
\RequirePackage{fancyhdr}
\fancypagestyle{plain}{%
  \fancyhf{}%
  \fancyfoot[C]{\mdseries\small\thepage}%
  \renewcommand*\headrulewidth{0pt}}

\fancypagestyle{rtthesisheadings}{%
  \fancyhf{}
  \fancyhead[LE,RO]{\normalfont\bfseries\thepage}%
  \fancyhead[RE]{\normalfont\mdseries\small\leftmark}%
  \fancyhead[LO]{\normalfont\mdseries\small\rightmark}%
  \renewcommand*\chaptermark[1]{\markboth{\@chapappname~\thechapter\quad##1}{}}%
  \renewcommand*\sectionmark[1]{\markright{\thesection\quad##1}}%
  \renewcommand*\headrulewidth{0.3pt}}
\pagestyle{rtthesisheadings}
\renewcommand*\chaptermark[1]{\markboth{\@chapappname~\thechapter\quad#1}{}}%
\renewcommand*\sectionmark[1]{\markright{\thesection\quad#1}}%


% Stuff that comes handy

\newcommand*\clearemptydoublepage{\clearpage\if@twoside \ifodd\c@page\else
  \thispagestyle{empty}\hbox{}\newpage\if@twocolumn\hbox{}\newpage\fi\fi\fi}

%%%%%%%%%%%%%%%%%%%%%%%
%%%  ABSTRACT ETC.  %%%
%%%%%%%%%%%%%%%%%%%%%%%

\newenvironment{abstract}[1][english]{%
  \clearemptydoublepage%
  \begin{otherlanguage}{#1}%
  \ifrt@UseHyperref
  \phantomsection\pdfbookmarkTopLevel{\abstractname}{theabsanchor-#1}%
  \fi
  \section*{\abstractname}%
  \markboth{\abstractname}{\abstractname}%
  \thispagestyle{plain}}{%
  \end{otherlanguage}%
  \clearemptydoublepage}

\newenvironment{preface}{%
  \clearemptydoublepage
  \thispagestyle{plain}%
  \ifrt@UseHyperref
  \phantomsection\pdfbookmarkTopLevel{\prefacename}{theprefaceanchor}%
  \fi
  \section*{\prefacename}%
  \markboth{\prefacename}{\prefacename}}{%
  \clearemptydoublepage}

\newenvironment{acknowledgments}{%
  \clearemptydoublepage
  \thispagestyle{plain}%
  \ifrt@UseHyperref
  \phantomsection\pdfbookmarkTopLevel{\acknowledgmentsname}{theackanchor}%
  \fi
  \section*{\acknowledgmentsname}%
  \markboth{\acknowledgmentsname}{\acknowledgmentsname}}{%
  \clearemptydoublepage}

\newenvironment{notation}[1][]{%
  \def\notationtabularstyle{#1}
  \def\notationtabularstylenew{new}
  \def\notationtabularstyleold{old}
  \ifx\notationtabularstyle\@empty
  % Do not redefine the notationtabular environment in this case.
  \else\ifx\notationtabularstyle\notationtabularstylenew
  \renewenvironment{notationtabular}{\notationtabular@modern}{\endnotationtabular@modern}
  \else\ifx\notationtabularstyle\notationtabularstyleold
  \renewenvironment{notationtabular}{\notationtabular@old}{\endnotationtabular@old}
  \else
  \ClassError{rtthesis}{%
    Bad option value to notation environment.\MessageBreak
    Legal values are "old" and "new"%
  }{%
    Bad option value ("\notationtabularstyle") to\MessageBreak
    notation environment.  Legal values are\MessageBreak
    "old" and "new"%
  }%
  \fi\fi\fi
  % The notation is put on chapter level, to match the table of contents which usually comes before.
  \clearemptydoublepage
  \thispagestyle{plain}%
  \ifrt@UseHyperref
  \phantomsection
  \fi
  \addcontentsline{toc}{chapter}{\notationname}
  \chapter*{\notationname}%
  \markboth{\notationname}{\notationname}}{%
  \clearemptydoublepage}

%%% Make good-looking tables.
\RequirePackage{array}
\RequirePackage{ctable}
\let\otoprule\toprule

\newenvironment{notationtabular@modern}[3]{%
  \addvspace{1\baselineskip}

  \begin{tabular}{>{\centering}m{0.18\textwidth} p{0.67\textwidth}}
    \multicolumn{2}{l}{\rlap{\hspace*{-3ex}\raisebox{1ex}{\textbf{\textothersc{#1}}}}}\\
    \toprule%
    \textbf{#2} & \textbf{#3} \\
    \otoprule%
  }{%
    \bottomrule%
  \end{tabular}
  }

\newenvironment{notationtabular@old}[3]{%
  \addvspace{1\baselineskip}

  \begin{tabular}{>{\centering}m{0.18\textwidth}|p{0.67\textwidth}}
    \multicolumn{2}{l}{\rlap{\hspace*{-3ex}\raisebox{1ex}{\textbf{\textothersc{#1}}}}}\\
    \hline
    \textbf{#2} & \parbox{\linewidth}{\centering\textbf{#3}} \\
    \hline
    \hline}{%
    \hline
  \end{tabular}
  }

\newenvironment{notationtabular}{\notationtabular@modern}{\endnotationtabular@modern}

%%%%%%%%%%%%%%%%%%%%%%%
%%%  CHAPTER HEADS  %%%
%%%%%%%%%%%%%%%%%%%%%%%

%%% Minor changes compared to book.cls:
%%% -  Using \clearemptydoublepage instead of \cleardoublepage
%%% -  Using \thispagestyle{empty} instead of \thispagestyle{plain}
\renewcommand\part{\if@openright\clearemptydoublepage\else\clearpage\fi
  \thispagestyle{empty}%
  \if@twocolumn
    \onecolumn
    \@tempswatrue
  \else
    \@tempswafalse
  \fi
  \null\vfil
  \secdef\@part\@spart}

\renewcommand\chapter{\if@openright\clearemptydoublepage\else\clearpage\fi
  \thispagestyle{plain}%
  \global\@topnum\z@
  \@afterindentfalse
  \secdef\@chapter\@schapter}

\DeclareFontFamily{OT1}{cmrd}{}
\DeclareFontShape{OT1}{cmrd}{bm}{n}{ <-> s * [2.0] cmr10}{}
\renewcommand*\@makechapterhead[1]{%
  \vspace*{14mm}%
  \noindent%
  \parbox[t][80pt][b]{\textwidth}{%
    \ifnum \c@secnumdepth >\m@ne%
      \if@mainmatter%
        \flushright%
        \begingroup%
          \bfseries%
          \fontsize{1.5cm}{3cm}\selectfont\SS@chapnamefont\@chapappname%
          {\fontsize{4cm}{4.2cm}\selectfont\SS@chapnumfont{~\thechapter}}\\%
        \endgroup%
      \fi%
    \fi%
    \rule{\textwidth}{1pt}%
  }\\[0pt]%
  \parbox[t][70pt][t]{\textwidth}{%
    \addvspace{6pt}%
    \flushright\sffamily\huge\bfseries\SS@chaptitlefont #1}%
  \vspace*{10pt}\par%
}
\renewcommand*\@makeschapterhead[1]{%
  \vspace*{14mm}%
  \noindent%
%%% One of the following two lines should be commented out, depending on whether one wants to allocate vertical space as if there would have been a chapter number.
%  \parbox[t][80pt][b]{\textwidth}{\rule{\textwidth}{1pt}}\\[0pt]%%% Allocate "chapter number" space.
  \rule{\textwidth}{1pt}\\[0pt]%%% Do not allocate "chapter number"  space.
%%%
  \parbox[t][70pt][t]{\textwidth}{%
    \addvspace{6pt}%
    \flushright\huge\sffamily\bfseries\SS@chaptitlefont{#1}}%
  \vspace*{10pt}\markboth{#1}{}\par%
}
\newcommand*\@makechapterparthead[1]{%
  \vspace*{14mm}%
  \noindent%
  \rule{\textwidth}{1pt}\\[0pt]%
  \parbox[t][70pt][t]{\textwidth}{%
    \addvspace{6pt}%
    \flushright\huge\sffamily\bfseries\SS@chaptitlefont{#1}}%
  \vspace*{10pt}\par%
}

\RequirePackage{appendix}
\newenvironment{chapter-appendix}{%
\clearpage
\begin{subappendices}%
\thispagestyle{plain}%
\@makechapterparthead{\appendixname}%
}{%
\end{subappendices}
}

% The following command may be used to set a prefix for the chapter number in a chapter heading.
% It may be useful for appendices, but exactly how it should be used is unclear at the time of
% writing.
\newcommand*\setchapapp[1]{\gdef\@chapappname{#1}}
\setchapapp{\relax}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  parskip.sty with adjusted spacing after sectioning commands  %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\ifrt@parskip

%%% The package was loaded early on, due to package ordering reasons.

%%% Adjust spacing around sectioning headings.

\RequirePackage{titlesec}
\titlespacing{\section}{0pt}{1em}{0.5ex}
\titlespacing{\subsection}{0pt}{0.5ex}{0ex}
\titlespacing{\subsubsection}{0pt}{0ex}{0ex}
\titlespacing{\paragraph}{0pt}{0pt}{1.5ex}

%%% Adjust spacing around equations.
\addto{\normalsize}{%
\setlength{\abovedisplayskip}{1.0\parskip}%
\setlength{\belowdisplayskip}{1.0\parskip}%
\setlength{\abovedisplayshortskip}{0.8\parskip}%
\setlength{\belowdisplayshortskip}{0.8\parskip}%
}

\fi

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
