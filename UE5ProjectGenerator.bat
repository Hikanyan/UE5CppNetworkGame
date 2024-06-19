@echo off
chcp 65001>nul

echo ディレクトリ Saved、Intermediate、および Binaries を削除しています...
if exist Saved rd /s /q Saved
if exist Intermediate rd /s /q Intermediate
if exist Binaries rd /s /q Binaries

:: 現在のディレクトリから .uproject ファイルを検索します
for %%i in (*.uproject) do set "uprojectpath=%%~fi"

:: .uproject ファイルが見つかった場合は、Visual Studioプロジェクトファイルを生成します
if defined uprojectpath (
    echo 検出されたプロジェクト: %uprojectpath%
    echo Visual Studioプロジェクトファイルを生成しています...
    "C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe" /projectfiles "%uprojectpath%"
    if %errorlevel% neq 0 (
        echo Visual Studioプロジェクトファイルの生成中にエラーが発生しました。
        pause
        exit /b %errorlevel%
    )
    echo Visual Studioプロジェクトファイルの生成が完了しました。
    
    echo プロジェクトを起動しますか？[Y/N]
    choice /C YN /N /M "はいの場合はYを、いいえの場合はNを押してください:"
    if errorlevel 2 goto end
    if errorlevel 1 start "" "%uprojectpath%"
) else (
    echo 現在のディレクトリに .uproject ファイルが見つかりませんでした。
    pause
)
@rem バンタンゲームアカデミー東京校 4年制ゲームプログラマ専攻 22生 作成者 宮﨑 光琉
:end
